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

    // TODO: delete this
    std::cout << "ScavTrap -----------------" << std::endl;
    std::cout << "name: " << name << std::endl;
    std::cout << "hitPoints: " << hitPoints << std::endl;
    std::cout << "energyPoints: " << energyPoints << std::endl;
    std::cout << "attackDamage: " << attackDamage << std::endl;
    std::cout << "--------------------------" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "Scavtrap " << name << " deconstruct called" << std::endl;
}
