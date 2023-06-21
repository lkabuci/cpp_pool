//
// Created by redone on 6/18/23.
//

#include "Cat.hpp"
#include "Dog.hpp"

int main() {

    const Animal *animals[10];
    for (int i = 0; i < 10; ++i) {
        if (i & 1)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < 10; ++i) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < 10; ++i) {
        delete animals[i];
    }

    return 0;
}
