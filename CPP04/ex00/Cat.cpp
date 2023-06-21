//
// Created by redone on 6/18/23.
//

#include "Cat.hpp"

Cat::Cat() {
    this->p_type = "Cat";
    std::cout << "+Cat constructor" << std::endl;
}

Cat::~Cat() {
    std::cout << "~Cat Deconstructor" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat) {
    *this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
    this->p_type = cat.p_type;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Mewoo Mewoo" << std::endl;
}
