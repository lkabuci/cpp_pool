//
// Created by redone on 6/21/23.
//

#ifndef POOL_ICE_HPP
#define POOL_ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {

public:
    Ice();

    Ice(const Ice &);

    Ice &operator=(const Ice &);

    virtual ~Ice();

    virtual AMateria *clone() const;

    virtual void use(ICharacter &target);
};

#endif //POOL_ICE_HPP
