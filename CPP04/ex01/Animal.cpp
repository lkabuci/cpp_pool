//
// Created by redone on 6/18/23.
//

#include "Animal.hpp"

Animal::Animal(const std::string &type) : p_type(type) {
    std::cout << "+Animal constructor" << std::endl;
}

Animal::Animal() : p_type("Nan") {
    std::cout << "+Animal constructor" << std::endl;
}

Animal::Animal(const Animal &animal) {
    *this = animal;
}

Animal &Animal::operator=(const Animal &animal) {
    p_type = animal.p_type;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Animal &animal) {
    os << "Animal type: " << animal.getType();
    return os;
}

const std::string &Animal::getType() const {
    return p_type;
}

Animal::~Animal() {
    std::cout << "~Animal Deconstructor" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "??????" << std::endl;
}
