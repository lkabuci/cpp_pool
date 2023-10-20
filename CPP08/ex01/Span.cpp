//
// Created by redone on 8/29/23.
//

#include "Span.hpp"

Span::Span(unsigned int maxNumbers) : N(maxNumbers) {
}

Span::Span(const Span& other) : N(other.N), list(other.list) {
}

Span& Span::operator=(const Span& other) {
    if (this == &other) {
        return *this;
    }
    this->N = other.N;
    this->list = other.list;
    return *this;
}

Span::~Span() {
}

void Span::addNumber(unsigned int number) {
    if (list.size() >= N)
        throw std::range_error("List out of range error.");
    list.push_back(number);
}

int Span::longestSpan() {
    if (list.size() <= 1)
        throw std::length_error("Not enough spans");
    int min = *std::min_element(list.begin(), list.end());
    int max = *std::max_element(list.begin(), list.end());

    return max - min;
}

int Span::shortestSpan() {
    if (list.size() <= 1)
        throw std::length_error("Not enough spans");
    int smallest = std::numeric_limits<int>::max();
    std::sort(list.begin(), list.end());
    for (std::vector<int>::iterator it = list.begin(); it != list.end() - 1; ++it) {
        int diff = *(it + 1) - *it;
        if (diff < smallest) {
            smallest = diff;
        }
    }

    return smallest;
}

void Span::fill() {

    std::srand(time(0));

    if (list.size() != 0)
        throw std::logic_error("list already contain elements");
    for (unsigned int i = 0; i < N; i++) {
        addNumber(i);
    }
    std::random_shuffle(list.begin(), list.end());
}
