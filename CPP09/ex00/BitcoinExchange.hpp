//
// Created by redone on 8/30/23.
//

#ifndef POOL_BITCOINEXCHANGE_HPP
#define POOL_BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <list>
#include <map>
#include <cstdlib>
#include <fstream>
#include <vector>

struct date {
    int year;
    int month;
    int day;
};

typedef std::vector<std::pair<struct date, float> > keyValue;

class BitcoinExchange {
private:
    const std::string& inputFileName;
    keyValue database;
    keyValue inputFile;

public:
    explicit BitcoinExchange(const std::string& filename);
};


#endif //POOL_BITCOINEXCHANGE_HPP
