#include "utils.h"

bool isAllDigit(std::string strNumber)
{
    for (std::size_t i = 0; i < strNumber.length(); ++i)
    {
        if (std::isdigit(strNumber[i]) == false)
        {
            return false;
        }
    }
    return true;
}

bool areContactInfoValids(
    std::string &firstName,
    std::string &lastName,
    std::string &nickName,
    std::string &phoneNumber,
    std::string &darkSecretk)
{
    std::string elements[] = {
        firstName,
        lastName,
        nickName,
        phoneNumber,
        darkSecretk};

    for (size_t i = 0; i < sizeof(elements) / sizeof(std::string); i++)
    {
        if (isStringEmpty(elements[i]) == true)
        {
            return (false);
        }
    }
    if (isAllDigit(phoneNumber) == false)
    {
        return false;
    }
    return (true);
}

std::string truncateString(std::string str)
{
    if (str.length() < 10)
    {
        return str;
    }
    std::string buffer = str.substr(0, 9);
    buffer += '.';
    return buffer;
}

std::string getInput(const std::string &prompt)
{
    std::string input;
    std::cout << prompt << "\t";
    std::getline(std::cin, input);
    if (std::cin.fail())
    {
        std::cerr << std::endl
                  << "Error: element can't be EOF" << std::endl;
        exit(EXIT_FAILURE);
    }
    return input;
}

bool isStringEmpty(const std::string &str)
{
    char blanks[] = " \t\n";
    size_t start;
    for (start = 0; start < str.length(); start++)
    {
        if (std::strchr(blanks, str[start]) == NULL)
            break;
    }
    return start == str.length();
}
