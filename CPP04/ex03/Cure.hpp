//
// Created by redone on 6/21/23.
//

#ifndef POOL_CURE_HPP
#define POOL_CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {

public:
    Cure();

    Cure(const Cure &);

    Cure &operator=(const Cure &);

    virtual ~Cure();

    virtual AMateria *clone() const;

    virtual void use(ICharacter &target);
};

#endif //POOL_CURE_HPP
