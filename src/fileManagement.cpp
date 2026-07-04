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
        }
    }
    catch (const fs::filesystem_error &error)
    {
        std::cerr << "Error copying file: file " << fileName
                  << " probably already exists in " << saveLocation << std::endl;
    }
}