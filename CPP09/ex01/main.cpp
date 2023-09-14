//
// Created by redone on 9/7/23.
//

#include "RPN.hpp"

int main(int argc, const char *argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: ./RPN {list of reverse polish notation}." << std::endl;
        return EXIT_FAILURE;
    }
    RPN rpn(argv[1]);
    rpn.displayResult();
    return 0;
}

