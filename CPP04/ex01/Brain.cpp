//
// Created by redone on 6/18/23.
//

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "+Brain Constructor" << std::endl;
}

Brain::~Brain() {
    std::cout << "~Brain Destructor" << std::endl;
}

Brain::Brain(const Brain &brain) {
    *this = brain;
}

Brain &Brain::operator=(const Brain &brain) {
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = brain.ideas[i];
    }
    return *this;
}
