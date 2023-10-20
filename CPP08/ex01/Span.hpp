//
// Created by redone on 8/29/23.
//

#ifndef POOL_SPAN_HPP
#define POOL_SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <limits>

class Span {
private:
    unsigned int N; // maximum of integers
    std::vector<int> list;

public:
    Span(unsigned int maxNumbers);
    Span(const Span&);
    Span& operator=( const Span&);
    ~Span( void );

    void addNumber(unsigned int number);
    void fill();
    int shortestSpan();
    int longestSpan();
};

#endif //POOL_SPAN_HPP
