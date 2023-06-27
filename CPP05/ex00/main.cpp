//
// Created by redone on 6/25/23.
//

#include "Bureaucrat.hpp"

int main(int argc, char *argv[]) {
    (void) argc, (void) argv;

    Bureaucrat mqadem("Mqadem", 149);


    try {
        std::cout << mqadem;
        mqadem--;
        std::cout << mqadem;
        mqadem--;
        std::cout << mqadem;
    }

    catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }


    return 0;
}

