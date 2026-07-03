#include <iostream>
#include "fileManagement.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Hello, sir!" << std::endl;

    FileManagement fm;

    if (!std::filesystem::exists(fm.filePath))
    {
        fm.createFolder(fm.filePath);
    }

    if (argc > 2)
    {
        if (std::string(argv[1]) == "copy")
        {
            std::string sourcePath = argv[2];
            fm.copyFile(sourcePath);
        }
    }

    return 0;
}