//
// Created by redone on 8/30/23.
//

#include "BitcoinExchange.hpp"

static bool isAllDigit(std::string str);
static std::pair<std::string, std::string> split( std::string str, char delim );
static void checkDate( std::string );
static float checkValue ( std::string );
static std::string &trim(std::string &s);
static bool isLeapYear(int year);
static void isDateExists(int year, int month, int day, std::string date);
static void checkSpaces(std::string date, std::string value);

BitcoinExchange::BitcoinExchange(const std::string filename) : _filename(filename) {
    _database = fillDataBase();
    parseInput();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _filename(other._filename), _database(other._database) {
}

BitcoinExchange& BitcoinExchange::operator= ( const BitcoinExchange& other) {
    if (this == &other) {
        return *this;
    }
    const_cast<std::string&>(_filename) = other._filename;
    _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

dict BitcoinExchange::fillDataBase( void ) {
    std::string     row;
    dict            data;
    std::fstream file( "data.csv" );

    if (!file.is_open()) {
        std::cerr << "Error: can't read from the database\n";
        exit ( EXIT_FAILURE );
    }
    std::getline (file, row);
    while ( std::getline(file, row) ) {
        std::pair<std::string, std::string> splited = split ( row, ',' );
        data.insert( std::pair<std::string, float> (splited.first, atof(splited.second.c_str())) );
    }
    return data;
}

void BitcoinExchange::parseInput( void ) {
    std::string row;
    std::fstream file ( _filename );
    if (file.fail()) {
        std::cerr << "Error: can't read input file\n";
        exit ( EXIT_FAILURE );
    }

    // parse header file
    std::getline(file, row);
    if (trim(row) != "date | value") {
        std::cerr << "Error: invalid input header file\n";
        exit (EXIT_FAILURE);
    }

    // parse row by row
    while ( std::getline(file, row) ) {
        std::string date;
        float       value;
        try {
            if (row.empty()) {
                continue;
            }
            std::pair<std::string, std::string> splited = split ( row, '|' );

            checkSpaces(splited.first, splited.second);
            date = trim(splited.first);
            checkDate(date);
            if (date < "2009-01-02") throw std::invalid_argument("Error: no bitcoin before 2009-01-02");
            value = checkValue(trim(splited.second));
            dict item;
            item.insert(std::make_pair(date, value));
            std::map<std::string, float>::iterator low = std::lower_bound(_database.begin(), _database.end(), *item.begin());
            low --;
            std::cout << date << " => " << value << " = " << value * (*low).second << std::endl;
        } catch (const std::invalid_argument& ex) {
            std::cout << ex.what() << "\n";
        }
    }
}

// Helpers
static std::pair<std::string, std::string> split( std::string str, char delim ) {
    std::stringstream   ss (str);
    std::string         key;
    std::string         value;

    std::string buffer;
    int counter = 0;
    if (std::count(str.begin(), str.end(), delim) != 1) {
        throw std::invalid_argument("Error: invalid argument \"" + str + "\"");
    }

    while (std::getline(ss, buffer, delim)) {
        if (counter == 0) {
            key = buffer;
        }
        else if (counter == 1) {
            value = buffer;
        }
        counter ++;
    }
    if (counter != 2) {
        throw std::invalid_argument("Error: invalid argument \"" + str + "\"");
    }

    return std::make_pair (key, value);
}


// "2021-10-12 "
static void checkDate( std::string date ) {
    std::stringstream ss ( date );
    int                  year;
    int                  month;
    int                  day;

    std::string             buffer;
    std::list<std::string>  listOfVals;

    if (std::count(date.begin(), date.end(), '-') != 2) {
        throw std::invalid_argument("Error: invalid date \"" + date + "\"");
    }

    int counter = 0;
    while (std::getline (ss, buffer, '-')) {
        if (isAllDigit(buffer)) {
            listOfVals.push_back(buffer);
        } else {
            throw std::invalid_argument("Error: not a valid date => " + date);
        }
        counter ++;
    }
    if (counter != 3) {
        throw std::invalid_argument("Error: not a valid date => " + date);
    }
    std::list<std::string>::iterator it = listOfVals.begin();
    year = atoi(it->c_str()); std::advance(it, 1);
    month = atoi(it->c_str()); std::advance(it, 1);
    day = atoi(it->c_str());
    isDateExists(year, month, day, date);
}

// Value checking helpers
static float checkValue ( std::string str ) {
    float value;
    std::stringstream ss ( str );

    if (std::count(str.begin(), str.end(), '.') > 1) {
        throw std::invalid_argument("more than one dot");
    }

    // std::cout << str << std::endl;
    for (size_t i = 0; str[i]; i++) {
        if (str[i] == '.') continue;
        if (!isdigit(str[i])) {
            // std::cout << str[i] << std::endl;
            throw std::invalid_argument("invalid character");
        }
    }

    if (ss >> value) {
        if (value > 1000) {
            throw std::invalid_argument("Error: too large a number.");
        }
        if (value < 0) {
            throw std::invalid_argument("Error: not a positive number");
        }
        return value;
    }
    throw std::invalid_argument ("Error: not a valid number.");
}

// Date checking helpers
static void isDateExists(int year, int month, int day, std::string date) {
    bool isExits = true;
    if (month > 12 || day > 31 || month <= 0 || day <= 0 || year < 0)
        isExits = false;
    if (day == 31 && ((month == 4) || (month == 6) || (month == 9) || (month == 11))) {
        isExits = false;
    }
    if (month == 2) {
        if (day >= 30) {
            isExits = false;
        }
        if (!isLeapYear(year) && day == 29) {
            isExits = false;
        }
    }
    if (isExits == false) {
        throw std::invalid_argument("Error: date does not exist => " + date);
    }
}

static bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
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
    ss >> std::noskipws;
    int val;
    ss >> val;
    return ss.eof();
}

static void checkSpaces(std::string date, std::string value) {
    if (date.empty() || value.empty()) {
        throw std::invalid_argument("Error empty value " + date);
    }
    if (std::count(date.begin(), date.end(), ' ') != 1 && std::count(value.begin(), value.end(), ' ') != 1) {
        throw std::invalid_argument("Error: invalid space pattern");
    }
    if (date[date.length() - 1] != ' ') throw std::invalid_argument("Error: invalid space pattern in date");
    for (size_t i = 0; i < date.length() - 1; i++) {
        if (std::isspace(date[i])) {
            throw std::invalid_argument("Error: invalid space pattern in date");
        }
    }
    if (value[0] != ' ')  throw std::invalid_argument("Error: invalid space pattern in value");
    for (size_t i = value.length() - 1; i > 0; i --) {
        if (std::isspace(value[i])) {
            throw std::invalid_argument("Error: invalid space pattern in value");
        }
    }
}
