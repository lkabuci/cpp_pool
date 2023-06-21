//
// Created by redone on 6/21/23.
//

#include "MateriaSource.hpp"

int MateriaSource::maxCount = 4;

MateriaSource::MateriaSource() : count(0) {
    for (int i = 0; i < maxCount; ++i) {
        learnedMaterias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    for (int i = 0; i < other.count; i++) {
        learnedMaterias[i] = other.learnedMaterias[i]->clone();
    }
    count = other.count;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this == &other) {
        return *this;
    }
    for (int i = 0; i < count; i++) {
        delete learnedMaterias[i];
        learnedMaterias[i] = NULL;
    }
    count = 0;
    for (int i = 0; i < other.count; i++) {
        learnedMaterias[i] = other.learnedMaterias[i]->clone();
        count++;
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < count; ++i) {
        delete learnedMaterias[i];
    }
}

void MateriaSource::learnMateria(AMateria *materia) {
    if (count == 4)
        return;
    learnedMaterias[count] = materia->clone();
    if (count <= 3)
        count++;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
    for (int i = 0; i < count; i++) {
        if (learnedMaterias[i]->getType() == type) {
            return learnedMaterias[i]->clone();
        }
    }
    return 0;
}
