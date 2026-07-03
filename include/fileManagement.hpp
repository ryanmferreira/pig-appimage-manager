#pragma once
#include <string>
#include <filesystem>

class FileManagement
{
public:
    std::string home = std::getenv("HOME");
    std::string defaultLocation = "/Programs/AppImages/";
    std::string saveLocation = home + defaultLocation;

    std::filesystem::path folderPath = saveLocation;

    void createFolder(std::filesystem::path &filePath);
    void copyFile(std::filesystem::path &sourcePath);
};