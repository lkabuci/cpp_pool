#ifndef CPP_POOL_UTILS_H
#define CPP_POOL_UTILS_H

#include <string>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

std::string getInput(const std::string& prompt);

std::string truncateString(std::string str);

bool isAllDigit(std::string strNumber);

bool isStringEmpty(const std::string& str);

bool areContactInfoValids(std::string &firstName, std::string &lastName,
                          std::string &nickName, std::string &phoneNumber,
                          std::string &darkSecretk);

#endif //CPP_POOL_UTILS_H
