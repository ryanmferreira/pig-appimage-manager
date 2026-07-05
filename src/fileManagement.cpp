#include <iostream>

#include "fileManagement.hpp"

void FileManagement::createFolder(fs::path &filePath)
{
    if (fs::create_directories(filePath))
    {
        std::cout << "\n> Folders created successfully!\nPath: " << filePath << std::endl;
    }
    else
    {
        std::cout << "\n> Folder already exists or failed to create.\n " << std::endl;
    }
}

void FileManagement::copyFile(fs::path &sourcePath)
{
    fs::path fileFolderName = sourcePath.stem();
    fs::path fileName = sourcePath.filename();

    fs::path appFolder = saveLocation / fileFolderName;

    createFolder(appFolder);

    fs::path destinationPath = appFolder / fileName;

    try
    {
        bool success = fs::copy_file(sourcePath, destinationPath);

        if (success)
        {
            std::cout << "\n> File copied successfully!\nPath: " << destinationPath << std::endl;
            giveExecPermissions(destinationPath);
        }
    }
    catch (const fs::filesystem_error &error)
    {
        std::cerr << "Error copying file: file " << fileName
                  << " probably already exists in " << saveLocation << std::endl;
    }
}

void FileManagement::giveExecPermissions(fs::path &sourcePath)
{
    try
    {
        fs::permissions(sourcePath, fs::perms::owner_exec, fs::perm_options::add);
        std::cout << "\n> Execution permission for the file " << sourcePath << " added successfully!" << std::endl;
    }
    catch (const fs::filesystem_error &error)
    {
        std::cerr << "\n> Error: " << error.what() << std::endl;
    }
}