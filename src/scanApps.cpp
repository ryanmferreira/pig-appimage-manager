#include <filesystem>
#include <vector>
#include <iostream>

#include "scanApps.hpp"
#include "fileManagement.hpp"

extern FileManagement fm;

std::vector<AppImageApp> scanInstalledApps(fs::path defaultFolder)
{
    std::vector<AppImageApp> installedApps;

    if (!fs::exists(defaultFolder))
    {
        return installedApps;
    }

    for (const auto &entry : fs::directory_iterator(defaultFolder))
    {
        if (entry.is_directory())
        {
            fs::path subFolder = entry.path();
            std::string appName = subFolder.filename().string();

            fs::path expectedBinary = subFolder / (appName + ".appimage");

            if (fs::exists(expectedBinary))
            {
                AppImageApp app;
                app.name = appName;
                app.binaryPath = expectedBinary;

                installedApps.push_back(app);
            }
        }
    }

    return installedApps;
}

void loadInstalledApps()
{
    std::vector<AppImageApp> installedApps = scanInstalledApps(fm.folderPath);

    std::cout << "\n> Installed AppImage apps:\n"
              << std::endl;

    for (const auto &app : installedApps)
    {
        std::cout << " - " << app.name << " (" << app.binaryPath << ")" << std::endl;
    }
}