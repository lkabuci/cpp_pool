//
// Created by redone on 8/30/23.
//

#include <algorithm>
#include "BitcoinExchange.hpp"

static struct date get_date(const std::string& str);

keyValue getKeyValues(const std::string &filename, char sep);

static inline std::string &trim(std::string &s);

BitcoinExchange::BitcoinExchange(const std::string &filename) : inputFileName(filename) {
    database = getKeyValues("data.csv", ',');
    inputFile = getKeyValues(inputFileName, '|');
}

keyValue getKeyValues(const std::string &filename, char sep) {
    keyValue kv;
    std::ifstream file;
    file.open(filename.c_str());
    if (file.fail()) {
        std::cerr << "Error: opening " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    std::vector<std::string> row;
    std::string line, word;

    getline(file, line);
    while (getline(file, line)) {
        row.clear();

        line = trim(line);

        std::stringstream s(line);

        while (getline(s, word, sep)) {
            word = trim(word);
            row.push_back(word);
        }
        struct date dt = get_date(row[0]);
        float exchange = atof(row[1].c_str());
        kv.push_back(std::make_pair(dt, exchange));
    }
    file.close();
    return kv;
}

struct date get_date(const std::string& str) {
    std::string value;
    std::stringstream ss(str);
    std::vector<std::string> row;

    while (getline(ss, value, '-')) {
        row.push_back(value);
    }

    return (struct date) {
            atoi(row[0].c_str()),
            atoi(row[1].c_str()),
            atoi(row[2].c_str())
    };
}

static inline std::string &trim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),std::not1(std::ptr_fun<int, int>(std::isspace))));
    s.erase(std::find_if(s.rbegin(), s.rend(),std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}
