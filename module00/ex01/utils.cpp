#include "utils.h"

bool isAllDigit(std::string strNumber) {
    for (std::size_t i = 0; i < strNumber.length(); ++i) {
        if (std::isdigit(strNumber[i]) == false) {
            return false;
        }
    }
    return true;
}

// TODO: search for a valid phone number is it always starting from 0
bool isValidPhoneNumber(std::string strNumber) {
    bool isPlus = false;
    if (strNumber[0] == '+') {
        isPlus = true;
        strNumber = strNumber.substr(1);
    } else if (strNumber[0] != '0')
        return false;
    if (isAllDigit(strNumber) == false)
        return false;
    if (isPlus && (strNumber.length() >= 10 && strNumber.length() <= 13))
        return true;
    return strNumber.length() == 10;
}

std::string truncateString(std::string str) {
    if (str.length() < 10) {
        return str;
    }
    std::string buffer = str.substr(0, 9);
    buffer += '.';
    return buffer;
}

std::string getInput(std::string prompt) {
    std::string input;
    std::cout << prompt << "\t";
    std::getline(std::cin, input);
    if (std::cin.eof()) {
        std::cerr << "Error: element can't be EOF" << std::endl;
        exit(EXIT_FAILURE);
    }
    return input;
}
