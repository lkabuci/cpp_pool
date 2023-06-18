//
// Created by redone on 6/18/23.
//

#ifndef POOL_CAT_HPP
#define POOL_CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
private:

public:
    Cat();

    virtual ~Cat();

    Cat(const Cat &cat);

    Cat &operator=(const Cat &cat);

    void makeSound() const;
};

#endif //POOL_CAT_HPP
