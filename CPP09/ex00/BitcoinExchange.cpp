//
// Created by redone on 8/30/23.
//

#include <algorithm>
#include "BitcoinExchange.hpp"

static bool isLeapYear(int year);

static bool isDateExists(struct date);

static struct date get_date(const std::string &str);

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

struct date get_date(const std::string &str) {
    std::string value;
    std::stringstream ss(str);
    std::vector<std::string> row;

    while (getline(ss, value, '-')) {
        row.push_back(value);
    }

    // check if a non integer exists
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; row[i][j]; j++) {
            if (std::isdigit(row[i][j]))
                continue;
            row[i] = "-1";
            break;
        }
        std::cout << row[i] << std::endl;
    }

    return (struct date) {
            atoi(row[0].c_str()),
            atoi(row[1].c_str()),
            atoi(row[2].c_str())
    };
}

static inline std::string &trim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

static bool isDateExists(struct date dt) {
    if (dt.month > 12 || dt.day > 31 || dt.month <= 0 || dt.day <= 0 || dt.year < 0)
        return false;
    if (((0x0A50 & (1 << dt.month)) != 0) && dt.day == 31) {
        return false;
    }
    if (dt.month == 2) {
        if (dt.day >= 30) {
            return false;
        }
        if (!isLeapYear(dt.year) && dt.day == 29) {
            return false;
        }
    }
    return true;
}

static bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}
