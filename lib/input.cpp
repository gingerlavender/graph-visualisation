/*!
 * \file
 * Файл с реализацией функций библиотеки input.h
*/ 
#include <iostream>
#include <limits>
#include "input.h"

char get_char(void) {
    char c;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(c);
    if (std::cin.eof()) {
        throw std::runtime_error("Have a nice day!");
    } else if (std::cin.bad()) {
        throw std::runtime_error(std::string("Failed to read number: ") + strerror(errno));
    }
    return c;
}
