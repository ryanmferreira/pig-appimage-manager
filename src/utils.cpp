#include <iostream>

void consoleClear()
{
    std::cout << "\e[2J\e[H" << std::flush;
}