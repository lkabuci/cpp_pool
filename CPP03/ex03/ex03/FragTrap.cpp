//
// Created by redone on 6/12/23.
//

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap Constructor of " << name << " called." << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Deconstruct called of " << this->name << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "Positive high five value" << std::endl;
}

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap Default Constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap) {
    std::cout << "FragTrap Copy Constructor called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap) {
    std::cout << "FragTrap Assignation Operator called." << std::endl;
    if (this != &fragTrap) {
        const_cast<std::string&>(name) = fragTrap.name;
        this->hitPoints = fragTrap.hitPoints;
        this->energyPoints = fragTrap.energyPoints;
        this->attackDamage = fragTrap.attackDamage;
    }
    return *this;
}
