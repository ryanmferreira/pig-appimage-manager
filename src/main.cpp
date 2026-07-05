#include <iostream>
#include <cctype>
#include <filesystem>

#include "main.hpp"
#include "utils.hpp"
#include "fileManagement.hpp"
#include "arguments.hpp"

FileManagement fm;

void checkDefaultFolder()
{
    if (!fs::exists(fm.folderPath))
    {
        std::cout << "> Default folder not detected. Creating a new one: " << std::endl;
        fm.createFolder(fm.folderPath);
    }
}

int main(int argc, char *argv[])
{
    std::cout << greetings() << std::endl;

    checkDefaultFolder();

    validateArguments(argc, argv);

    return 0;
}

std::string greetings()
{
    std::string user = fm.user;

    user[0] = std::toupper(user[0]);
    std::string name = user;

    return "> Hello, " + name + "!";
}
