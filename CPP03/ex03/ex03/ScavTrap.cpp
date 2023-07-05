//
// Created by redone on 6/12/23.
//

#include "ScavTrap.hpp"

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gatekeeper mode." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " constructor called." << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "Scavtrap " << name << " deconstruct called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap.name) {
    hitPoints = scavTrap.hitPoints;
    energyPoints = scavTrap.energyPoints;
    attackDamage = scavTrap.attackDamage;
    std::cout << "ScavTrap " << name << " copy constructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) {
    hitPoints = scavTrap.hitPoints;
    energyPoints = scavTrap.energyPoints;
    attackDamage = scavTrap.attackDamage;
    std::cout << "ScavTrap " << name << " assignation operator called." << std::endl;
    return *this;
}

ScavTrap::ScavTrap() : ClapTrap("default") {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " default constructor called." << std::endl;
}
