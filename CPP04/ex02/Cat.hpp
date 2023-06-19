//
// Created by redone on 6/18/23.
//

#ifndef POOL_CAT_HPP
#define POOL_CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain *brain;

public:
    Cat();

    virtual ~Cat();

    Cat(const Cat &cat);

    Cat &operator=(const Cat &cat);

    void makeSound() const;
};

#endif //POOL_CAT_HPP
