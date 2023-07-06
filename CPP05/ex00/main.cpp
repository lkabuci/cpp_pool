//
// Created by redone on 6/25/23.
//

#include "Bureaucrat.hpp"

int main(int argc, char *argv[]) {
    (void) argc, (void) argv;

    try {
        Bureaucrat mqadem("Mqadem", 3);
        mqadem.demotion();
        std::cout << mqadem;
        mqadem.promotion();
        std::cout << mqadem;
    }

    catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}
