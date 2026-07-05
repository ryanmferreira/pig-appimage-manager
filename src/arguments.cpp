#include <iostream>

#include "main.hpp"
#include "fileManagement.hpp"
#include "arguments.hpp"

extern FileManagement fm;

void handleHelp()
{
    std::cout << "\n> Available commands:\n"
              << " help          - Display this help message\n"
              << " copy <source> - Copy a file to the default folder\n"
              << " open <file>   - Open a file\n"
              << " home <file>   - Create a .home folder for the specified app\n"
              << std::endl;
}

void handleInvalidCommand()
{
    std::cout << "\n> You typed an invalid command." << std::endl;
}

void validateArguments(int argc, char *argv[])
{
    std::string validCommands[] = {"copy", "open", "home", "help", "--help", "-h"};
    bool isValidCommand = false;

    for (const auto &cmd : validCommands)
    {
        if (cmd == argv[1])
        {
            isValidCommand = true;
            break;
        }
    }

    if (argc < 2)
    {
        std::cout << "\n> No command provided. Use 'help' to see available commands." << std::endl;
        return;
    }

    if (!isValidCommand)
    {
        handleInvalidCommand();
        handleHelp();
        return;
    }

    std::string command = argv[1];

    if (command == "help" || command == "--help" || command == "-h")
    {
        handleHelp();
        return;
    }

    if (argc < 3)
    {
        std::cout << "\n> Error: '" << command << "' requires a file path.\n " << "Usage: pig " << command << " <path>" << std::endl;
        return;
    }

    fs::path targetPath = argv[2];

    if (command == "copy")
    {
        std::cout << "\n> Adding file to apps folder..." << std::endl;
        fm.copyFile(targetPath);
    }
    else if (command == "open")
    {
        fm.openFile(targetPath);
    }
    else if (command == "home")
    {
        fm.createAppHomeFolder(targetPath);
    }
}