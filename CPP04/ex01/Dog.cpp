//
// Created by redone on 6/18/23.
//

#include "Dog.hpp"

Dog::Dog() : brain(new Brain) {
    p_type = "Dog";
    std::cout << "+Dog constructor" << std::endl;
}

Dog::~Dog() {
    std::cout << "~Dog deconstructor" << std::endl;
    delete brain;
}

Dog::Dog(const Dog &dog) : Animal(dog) {
    *this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
    this->p_type = dog.p_type;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Haw Haw" << std::endl;
}
