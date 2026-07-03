#include "fileManagement.hpp"
#include <iostream>

void FileManagement::createFolder(std::filesystem::path &filePath)
{
    if (std::filesystem::create_directories(filePath))
    {
        std::cout << "\nFolders created successfully!\nPath: " << filePath << std::endl;
    }
    else
    {
        std::cout << "\nFolder failed to create or already exists.\n " << std::endl;
    }
}

void FileManagement::copyFile(std::string &sourcePath)
{
    std::string fileName = std::filesystem::path(sourcePath).filename().string();
    std::string fileFolderName = std::filesystem::path(sourcePath).stem().string();

    std::filesystem::path appFolder = std::filesystem::path(defaultFolder) / fileFolderName;

    createFolder(appFolder);
    std::filesystem::path destinationPath = appFolder / fileName;

    try
    {
        bool success = std::filesystem::copy_file(sourcePath, destinationPath);

        if (success)
        {
            std::cout << "\nFile copied successfully!\nPath: " << destinationPath << std::endl;
        }
    }
    catch (const std::filesystem::filesystem_error &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
}