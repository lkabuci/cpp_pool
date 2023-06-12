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

// TODO: check for this positive value
void FragTrap::highFivesGuys() {
    std::cout << "<Positive> high five value" << std::endl;
}
