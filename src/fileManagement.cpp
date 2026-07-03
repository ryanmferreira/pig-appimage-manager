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

void FileManagement::copyFile(std::filesystem::path &sourcePath)
{
    std::filesystem::path fileFolderName = std::filesystem::path(sourcePath).stem().string();
    std::filesystem::path fileName = std::filesystem::path(sourcePath).filename().string();

    std::filesystem::path appFolder = defaultFolder / fileFolderName;

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
    catch (const std::filesystem::filesystem_error &error)
    {
        std::cerr << "Error: " << error.what() << '\n';
    }
}