//
// Created by Redouane Elkaboussi on 6/2/23.
//

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->_name = name;
	this->_isWeapon = false;
}

HumanB::~HumanB() {
}

void HumanB::setName(std::string newName) {
	this->_name = newName;
}

void HumanB::setWeapon(Weapon weapon) {
	this->_weapon = weapon;
	this->_isWeapon = true;
}

void HumanB::attack() {
	if (this->_isWeapon)
		std::cout << this->_name << " attacks with their " << this->_weapon.getType() << "." << std::endl;
	else
		std::cout << this->_name << " attacks with no weapon." << std::endl;
}