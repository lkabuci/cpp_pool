//
// Created by redone on 7/7/23.
//

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <iomanip>

void ScalarConverter::convert(const std::string &literal) {
    // Conversion to char
    if (std::atoi(literal.c_str()) < 255 && std::atoi(literal.c_str()) > -256) {
        char c = std::atoi(literal.c_str());
        if (std::isprint(c))
            std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }

    // Conversion to int
    std::stringstream ssi(literal);
    int i;
    if (ssi >> i) {
        std::cout << "int: " << static_cast<int>(i) << std::endl;
    } else {
        std::cout << "int: impossible" << std::endl;
    }

    // Conversion to float
    std::string literalWithoutSuffix = literal;
    literalWithoutSuffix.erase(std::remove(literalWithoutSuffix.begin(), literalWithoutSuffix.end(), 'f'), literalWithoutSuffix.end());
    std::stringstream ssf(literalWithoutSuffix);
    float f;
    if (ssf >> f) {
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(f) << "f" << std::endl;
    } else {
        std::cout << "float: impossible" << std::endl;
    }

    // Conversion to double
    std::stringstream ssd(literalWithoutSuffix);
    double d;
    if (ssd >> d) {
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(d) << std::endl;
    } else {
        std::cout << "double: impossible" << std::endl;
    }
}
