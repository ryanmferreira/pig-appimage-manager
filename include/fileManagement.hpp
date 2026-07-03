#pragma once
#include <string>
#include <filesystem>

class FileManagement
{
public:
    std::string home = std::getenv("HOME");
    std::string defaultFolder = home + "/Programs/AppImages/";
    std::filesystem::path filePath = defaultFolder;

    void createFolder(std::filesystem::path &filePath);
    void copyFile(std::string &sourcePath);
};