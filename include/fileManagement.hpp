#pragma once
#include <string>
#include <filesystem>

class FileManagement
{
public:
    std::filesystem::path home = std::getenv("HOME");
    std::filesystem::path defaultFolder = home / "/Programs/AppImages/";
    std::filesystem::path filePath = defaultFolder;

    void createFolder(std::filesystem::path &filePath);
    void copyFile(std::filesystem::path &sourcePath);
};