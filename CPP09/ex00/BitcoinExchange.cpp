//
// Created by redone on 8/30/23.
//

#include "BitcoinExchange.hpp"

static vData parseFile(const std::string &filename, char delim);
static struct data parseRow(std::string row, char delim);
static void parseDate(struct data *dt, std::string &date);
static float parseValue(std::string &value, char delim);
static std::string trimallspaces(std::string basicString);
static std::string &trim(std::string &s);
static bool isDateExists(struct data data);
static bool isLeapYear(int year);
static bool isAllDigit(std::string str);
static bool compareDate(const struct data &dt1, const struct data &dt2);
static bool areDatesEqual(const struct data &dt1, const struct data &dt2);


BitcoinExchange::BitcoinExchange(const std::string &filename) : inputFileName(filename) {
    database = parseFile("data.csv", ',');
    inputFile = parseFile(inputFileName, '|');
    std::sort(database.begin(), database.end(), compareDate);
}

// database first
void BitcoinExchange::display() {
    for (vData::iterator inputItr = inputFile.begin(); inputItr != inputFile.end(); ++inputItr) {
        if (!isDateExists(*inputItr)) {
            std::cout << "Error: bad input => " << inputItr->iso << std::endl;
            continue;
        }
        if (inputItr->value == -1) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (inputItr->value == -2) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        // 2011-01-03 => 3 = 0.9
        vData::iterator dbPrevItr = database.begin();
        for (vData::iterator dbItr = database.begin(); dbItr != database.end(); ++ dbItr) {
            if (areDatesEqual(*inputItr, *dbItr)) {
                std::cout << inputItr->iso << " => " << inputItr->value << " = " << inputItr->value * dbItr->value << std::endl;
                break;
            }
            else if (compareDate(*inputItr, *dbItr)) {
                std::cout << inputItr->iso << " => " << inputItr->value << " = " << inputItr->value * dbPrevItr->value << std::endl;
                break;
            }
            dbPrevItr = dbItr;
        }
    }
}

static vData parseFile(const std::string &filename, char delim) {
    std::fstream file;
    file.open(filename.c_str());
    if (file.fail()) {
        std::cerr << "Error while opening the file" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string row;
    vData vdata;

    std::getline(file, row);
    if (trimallspaces(row) != "date|value" && delim == '|') {
        std::cerr << "invalid header file" << std::endl;
        exit(EXIT_FAILURE);
    }

    while (std::getline(file, row)) {
        trim(row);
        struct data dt = parseRow(row, delim);
        vdata.push_back(dt);
    }

    file.close();
    return vdata;
}

static std::string trimallspaces(std::string basicString) {
    std::string noSpaceStr;
    for (int i = 0; basicString[i]; i++) {
        if (!std::isspace(basicString[i])) {
            noSpaceStr += basicString[i];
        }
    }
    return noSpaceStr;
}

static struct data parseRow(std::string row, char delim) {
    std::stringstream ss(row);
    std::string buffer;
    int counter = 0;
    std::vector<std::string> vstring;
    struct data data = {};

    data.value = -1;

    while (std::getline(ss, buffer, delim)) {
        vstring.push_back(trim(buffer));
        ++counter;
    }
    data.iso = vstring[0];
    parseDate(&data, vstring[0]);
    if (counter == 2) {
        data.value = parseValue(vstring[1], delim);
    }
    return data;
}

static void parseDate(struct data *dt, std::string &date) {
    std::stringstream ss(date);
    std::string buffer;
    std::vector<std::string> strvect;

    dt->day = -1;
    dt->month = -1;
    dt->year = -1;
    int counter = 0;

    while (std::getline(ss, buffer, '-')) {
        if (isAllDigit(buffer)) {
            strvect.push_back(buffer);
        } else {
            strvect.push_back(std::string("-1"));
        }
        ++counter;
    }
    if (counter != 3) {
        return;
    }
    dt->year = atoi(strvect[0].c_str());
    dt->month = atoi(strvect[1].c_str());
    dt->day = atoi(strvect[2].c_str());
}

// -1 means negative value
// -2 means too large number
static float parseValue(std::string &value, char delim) {
    std::stringstream ss(value);
    std::string buffer;
    float ret;
    ss >> ret;
    ss >> std::ws;
    if (!ss.eof() || ret < 0) {
        return -1;
    }
    if (delim == '|' && ret > 1000) {
        return -2;
    }
    return ret;
}

static std::string &trim(std::string &s) {
    std::string::iterator lit = s.begin();
    while (lit != s.end() && std::isspace(*lit)) {
        ++lit;
    }
    s.erase(s.begin(), lit);
    std::string::reverse_iterator rit = s.rbegin();
    while (rit != s.rend() && std::isspace(*rit)) {
        ++rit;
    }
    s.erase(rit.base(), s.end());
    return s;
}

static bool isAllDigit(std::string str) {
    std::stringstream ss(str);
    int val;
    ss >> val;
    ss >> std::ws;
    return ss.eof();
}

static bool isDateExists(struct data data) {
    if (data.month > 12 || data.day > 31 || data.month <= 0 || data.day <= 0 || data.year < 0)
        return false;
    if (data.day == 31 && ((data.month == 4) || (data.month == 6) || (data.month == 9) || (data.month == 11))) {
        return false;
    }
    if (data.month == 2) {
        if (data.day >= 30) {
            return false;
        }
        if (!isLeapYear(data.year) && data.day == 29) {
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

static bool compareDate(const struct data &dt1, const struct data &dt2) {
    if (dt1.year < dt2.year) {
        return true;
    } else if (dt1.year > dt2.year) {
        return false;
    } else { // Years are equal, compare months
        if (dt1.month < dt2.month) {
            return true;
        } else if (dt1.month > dt2.month) {
            return false;
        } else { // Months are equal, compare days
            return dt1.day < dt2.day;
        }
    }
}

static bool areDatesEqual(const struct data &dt1, const struct data &dt2) {
    return dt1.day == dt2.day && dt1.month == dt2.month && dt1.year == dt2.year;
}
