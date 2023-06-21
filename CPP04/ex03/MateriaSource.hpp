//
// Created by redone on 6/21/23.
//

#ifndef POOL_MATERIASOURCE_HPP
#define POOL_MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class IMateriaSource;

class MateriaSource : public IMateriaSource {
private:
    AMateria *learnedMaterias[4];
    int count;
    static int maxCount;

public:
    MateriaSource();

    MateriaSource(const MateriaSource &);

    MateriaSource &operator=(const MateriaSource &);

    virtual ~MateriaSource();

    virtual void learnMateria(AMateria *materia);

    virtual AMateria *createMateria(const std::string &type);

};

#endif //POOL_MATERIASOURCE_HPP
