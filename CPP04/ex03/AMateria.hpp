//
// Created by redone on 6/21/23.
//

#ifndef POOL_AMATERIA_HPP
#define POOL_AMATERIA_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class ICharacter;

class AMateria {

protected:
    std::string type;

public:
    AMateria();

    AMateria(const AMateria &);

    AMateria &operator=(const AMateria &);

    virtual ~AMateria();

    AMateria(std::string const &type);

    std::string const &getType() const;

    virtual AMateria *clone() const = 0;

    virtual void use(ICharacter &target);
};

#endif //POOL_AMATERIA_HPP
