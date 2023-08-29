//
// Created by redone on 8/29/23.
//

#include "Span.hpp"

int main() {

    Span sp(10);

    try {
        sp.fill();
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
