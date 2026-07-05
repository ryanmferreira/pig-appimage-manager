#include <iostream>

#include "main.hpp"
#include "fileManagement.hpp"
#include "arguments.hpp"

extern FileManagement fm;

void handleHelp()
{
    std::cout << "\n> Available commands:\n"
              << " --help        - Display this help message\n"
              << " copy <source> - Copy a file to the default folder\n"
              << " open <file>   - Open a file\n"
              << " home <file>   - Create a .home folder for the specified app\n"
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

void handleExecute(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "\n> Error: 'execute' requires a file path.\nUsage: pig execute <file_path>" << std::endl;
        return;
    }

    fs::path filePath = argv[2];
    fm.openFile(filePath);
}

void handleCreateHomeFolder(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "\n> Error: 'home' requires a file path.\nUsage: pig home <file_path>" << std::endl;
        return;
    }

    fs::path filePath = argv[2];
    fm.createAppHomeFolder(filePath);
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
    else if (command == "open")
    {
        std::cout << "\n> Executing file..." << std::endl;
        handleExecute(argc, argv);
    }
    else if (command == "home")
    {
        std::cout << "\n> Creating home folder..." << std::endl;
        handleCreateHomeFolder(argc, argv);
    }
    else
    {
        std::cout << "\n> Invalid command. Use 'help' to see usage." << std::endl;
    }
}