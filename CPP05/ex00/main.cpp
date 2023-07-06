//
// Created by redone on 6/25/23.
//

#include "Bureaucrat.hpp"

int main(int argc, char *argv[]) {
    (void) argc, (void) argv;

    try {
        Bureaucrat mqadem("Mqadem", 150);
        std::cout << mqadem;
        mqadem.demotion();
        std::cout << mqadem;
        mqadem.demotion();
        std::cout << mqadem;
        mqadem.demotion();
        std::cout << mqadem;
    }

    catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}
