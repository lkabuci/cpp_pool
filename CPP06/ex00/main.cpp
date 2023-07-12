//
// Created by redone on 7/9/23.
//

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }

    std::string literal(argv[1]);
    ScalarConverter::convert(literal);

    return 0;
}

