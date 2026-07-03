#include <iostream>
#include "fileManagement.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Hello, sir!\n " << std::endl;

    FileManagement fm;

    if (!std::filesystem::exists(fm.folderPath))
    {
        std::cout << "Default folder not detected. Creating a new one: " << std::endl;
        fm.createFolder(fm.folderPath);
    }

    if (argc > 2)
    {
        if (std::string(argv[1]) == "copy")
        {
            std::filesystem::path sourcePath = argv[2];
            fm.copyFile(sourcePath);
        }
    }

    return 0;
}