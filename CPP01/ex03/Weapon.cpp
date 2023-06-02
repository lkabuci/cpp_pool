#include "Weapon.hpp"

Weapon::Weapon() {
}

Weapon::Weapon(std::string name) {
    this->_type = name;
}

Weapon::~Weapon() {
}

const std::string& Weapon::getType( void ) {
    return this->_type;
}

void Weapon::setType( std::string newType ) {
    this->_type = newType;
}
