/*!
 * \file
 * Файл для работы со вводом
*/
#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <cstring>
#include <string>
#include <limits>

/*!
 * Функция для получения символа из потока ввода.
 * \return Вводимый символ
 * \throw std::runtime_error В случае конца файла или проблем с потоком ввода
*/ 
char get_char(void);

/*!
 * Функция для получения числа из потока ввода.
 * \tparam T Тип числа
 * \param min Минимальное значение типа
 * \param max Максимальное значение типа
 * \return Вводимое число
 * \throw std::runtime_error в случае конца файла или проблем с потоком ввода
*/
template<class T>
T get_num(T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max()) {
    T num;
    do {
        std::cin >> num;
        if (std::cin.eof()) {
            throw std::runtime_error("Have a nice day!");
        } else if (std::cin.bad()) {
            throw std::runtime_error(std::string("Failed to read number: ") + strerror(errno));
        } else if (std::cin.fail() || num < min || num > max) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Try again!\n\n";
        } else {
            return num;
        }
    } while (true);
    return num;
}

#endif
