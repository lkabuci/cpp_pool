//
// Created by redone on 8/30/23.
//

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, const char *argv[]) {

    // check args
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange bitcoinExchange(argv[1]);

    return 0;
}
