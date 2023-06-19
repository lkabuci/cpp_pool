//
// Created by redone on 6/18/23.
//

#ifndef POOL_DOG_HPP
#define POOL_DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain *brain;

public:
    Dog();

    virtual ~Dog();

    Dog(const Dog &dog);

    Dog &operator=(const Dog &dog);

    void makeSound() const;
};

#endif //POOL_DOG_HPP
