#pragma once
#include <filesystem>

namespace fs = std::filesystem;

class FileManagement
{
public:
    const std::string user = std::getenv("USER");
    const std::string home = std::getenv("HOME");

    std::string defaultLocation = "/Programs/AppImages/";
    std::string saveLocation = home + defaultLocation;

    fs::path folderPath = saveLocation;

    void createFolder(fs::path &filePath);
    void copyFile(fs::path &sourcePath);
    void giveExecPermissions(fs::path &filePath);
    void openFile(fs::path &filePath);
};