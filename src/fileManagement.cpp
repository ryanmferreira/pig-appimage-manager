#include <iostream>

#include "fileManagement.hpp"

void FileManagement::createFolder(fs::path &filePath)
{
    if (fs::create_directories(filePath))
    {
        std::cout << "\n> Folder " << filePath << " created successfully!" << std::endl;
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
            std::cout << "\n> Successfuly copied file " << destinationPath.filename() << " to " << destinationPath << std::endl;
            giveExecPermissions(destinationPath);
        }
    }
    catch (const fs::filesystem_error &error)
    {
        std::cerr << "Error copying file: maybe the file " << fileName << " already exists in " << saveLocation << std::endl;
    }
}

void FileManagement::giveExecPermissions(fs::path &filePath)
{
    try
    {
        fs::permissions(filePath, fs::perms::owner_exec, fs::perm_options::add);
        std::cout << "\n> Added execution permission for the file " << filePath.filename() << std::endl;
    }
    catch (const fs::filesystem_error &error)
    {
        std::cerr << "\n> Error: " << error.what() << std::endl;
    }
}

void FileManagement::openFile(fs::path &filePath)
{
    std::cout << "\n> Attempting to open file " << filePath.filename() << "!" << std::endl;

    bool success = std::system(filePath.c_str());

    if (success)
    {
        std::cout << "\n> File " << filePath.filename() << " executed successfully!" << std::endl;
    }
    else
    {
        std::cerr << "\n> Error: Failed to open the file " << filePath << std::endl;
    }
}

void FileManagement::createAppHomeFolder(fs::path &filePath)
{
    std::cout << "\n> Creating .home folder for " << filePath.filename() << std::endl;

    fs::path appHomeFolder = filePath.string() + ".home";
    createFolder(appHomeFolder);
}