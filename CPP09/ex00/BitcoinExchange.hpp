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
#include <algorithm>
#include <map>
#include <list>

typedef std::map<std::string, float> dict;

class BitcoinExchange {
public:
    explicit BitcoinExchange(const std::string filename);
    BitcoinExchange(const BitcoinExchange&);
    BitcoinExchange& operator=(const BitcoinExchange&);
    ~BitcoinExchange();

private:
    const std::string   _filename;
    dict                _database;

    // Private methods
    dict                fillDataBase( void );
    void                parseInput ( void );
};


#endif //POOL_BITCOINEXCHANGE_HPP
