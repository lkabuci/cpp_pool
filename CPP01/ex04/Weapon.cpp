#include "Weapon.hpp"

Weapon::Weapon() {
}

Weapon::Weapon(std::string name) {
	this->type = name;
}

Weapon::~Weapon() {
}

const std::string Weapon::getType() const {
	return this->type;
}

void	Weapon::setType(std::string type) {
	this->type = type;
}