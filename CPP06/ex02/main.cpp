//
// Created by redone on 7/12/23.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate();

void identify(Base *p);

void identify(Base &p);

int main() {
    std::srand(std::time(NULL));

    Base *obj = generate();

    identify(obj);
    identify(*obj);

    delete obj;

    return 0;
}

Base *generate() {
    srand(time(NULL));
    int idx = rand() % 3;
    switch (idx) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    };
    return NULL;
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p) != NULL) {
        std::cout << "A";
    } else if (dynamic_cast<B *>(p) != NULL) {
        std::cout << "B";
    } else if (dynamic_cast<C *>(p) != NULL) {
        std::cout << "C";
    }
    std::cout << std::endl;
}

void identify(Base &p) {
    try {
        identify(&p);
    }
    catch (...) {
        std::cout << "Unknown type" << std::endl;
    }
}
