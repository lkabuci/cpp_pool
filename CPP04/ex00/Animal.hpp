//
// Created by redone on 6/18/23.
//

#ifndef POOL_ANIMAL_HPP
#define POOL_ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
public:
    Animal();

    explicit Animal(const std::string &type);

    Animal(const Animal &animal);

    Animal &operator=(const Animal &animal);

    const std::string &getType() const;

    virtual ~Animal();

    virtual void makeSound() const;

protected:
    std::string p_type;

};

std::ostream &operator<<(std::ostream &os, const Animal &animal);

#endif //POOL_ANIMAL_HPP
