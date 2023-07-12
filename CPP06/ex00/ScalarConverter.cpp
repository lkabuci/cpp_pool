//
// Created by redone on 7/7/23.
//

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>

void ScalarConverter::convert(const std::string &literal) {
    // Conversion to char
    if (std::atoi(literal.c_str()) < 255 && std::atoi(literal.c_str()) > -256) {
        char c = std::atoi(literal.c_str());
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }

    // Conversion to int
    std::istringstream iss(literal);
    int i;
    if (iss >> i) {
        std::cout << "int: " << i << std::endl;
    } else {
        std::cout << "int: impossible" << std::endl;
    }

    // Conversion to float
    std::istringstream issf(literal);
    float f;
    if (issf >> f) {
        std::cout << "float: " << f << "f" << std::endl;
    } else {
        std::cout << "float: impossible" << std::endl;
    }

    // Conversion to double
    std::istringstream issd(literal);
    double d;
    if (issd >> d) {
        std::cout << "double: " << d << std::endl;
    } else {
        std::cout << "double: impossible" << std::endl;
    }
}
