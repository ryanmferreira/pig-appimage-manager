#pragma once

namespace fs = std::filesystem;

struct AppImageApp
{
    std::string name;
    fs::path binaryPath;
};

std::vector<AppImageApp> scanInstalledApps(fs::path defaultFolder);
void loadInstalledApps();