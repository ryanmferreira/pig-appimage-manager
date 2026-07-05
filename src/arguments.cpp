#include <iostream>

#include "main.hpp"
#include "fileManagement.hpp"
#include "arguments.hpp"

extern FileManagement fm;

void handleHelp()
{
    std::cout << "\n> Available commands:\n"
              << "  --help        - Display this help message\n"
              << "  copy <source> - Copy a file to the default folder\n"
              << std::endl;
}

void handleCopy(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "\n> Error: 'copy' requires a source file path.\nUsage: pig copy <source_path>" << std::endl;
        return;
    }

    fs::path sourcePath = argv[2];
    fm.copyFile(sourcePath);
}

void validateArguments(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "\n> No command provided. Use 'help' to see available commands." << std::endl;
        return;
    }

    std::string command = argv[1];

    if (command == "help" || command == "--help" || command == "-h")
    {
        handleHelp();
    }
    else if (command == "copy")
    {
        std::cout << "\n> Adding file to apps folder..." << std::endl;
        handleCopy(argc, argv);
    }
    else
    {
        std::cout << "\n> Invalid command. Use 'help' to see usage." << std::endl;
    }
}