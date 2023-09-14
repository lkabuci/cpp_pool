//
// Created by redone on 8/30/23.
//

#ifndef POOL_BITCOINEXCHANGE_HPP
#define POOL_BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>

struct data {
    int year;
    int month;
    int day;
    float value;
    std::string iso;
};

typedef std::vector<struct data> vData;

class BitcoinExchange {
private:
    const std::string& inputFileName;
    vData database;
    vData inputFile;

public:
    explicit BitcoinExchange(const std::string& filename);
    void display( void );
};


#endif //POOL_BITCOINEXCHANGE_HPP
