//
// Created by redone on 6/21/23.
//

#ifndef POOL_IMATERIASOURCE_HPP
#define POOL_IMATERIASOURCE_HPP

#include "AMateria.hpp"

class AMateria;

class IMateriaSource {
public:
    virtual ~IMateriaSource() {}

    virtual void learnMateria(AMateria *) = 0;

    virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif //POOL_IMATERIASOURCE_HPP
