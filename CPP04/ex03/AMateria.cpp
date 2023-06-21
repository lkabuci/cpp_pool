//
// Created by redone on 6/21/23.
//

#include "AMateria.hpp"

AMateria::AMateria() : type("None") {
}

AMateria::AMateria(const std::string &type) : type(type) {
}

AMateria::AMateria(const AMateria &other) {
    *this = other;
}

AMateria &AMateria::operator=(const AMateria &other) {
    if (this == &other)
        return *this;
    type = other.type;
    return *this;
}

AMateria::~AMateria() {
}

void AMateria::use(ICharacter &target) {
    (void) target;
}

std::string const &AMateria::getType() const {
    return type;
}
