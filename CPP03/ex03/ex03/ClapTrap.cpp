//
// Created by redone on 6/11/23.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name) : name(name) {
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout << "ClapTrap constructor called. Name: " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) : name(clapTrap.name) {
    hitPoints = clapTrap.hitPoints;
    energyPoints = clapTrap.energyPoints;
    attackDamage = clapTrap.attackDamage;
    std::cout << "ClapTrap copy constructor called. Name: " << name << std::endl;
}

ClapTrap::ClapTrap() : name("default") {
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout << "ClapTrap default constructor called. Name: " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &clapTrap) {
    hitPoints = clapTrap.hitPoints;
    energyPoints = clapTrap.energyPoints;
    attackDamage = clapTrap.attackDamage;
    std::cout << "ClapTrap assignation operator called. Name: " << name << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called. Name: " << name << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (hitPoints == 0 || energyPoints == 0) {
        std::cout << "ClapTrap " << name << " can't attack. Not enough hit points or energy points." << std::endl;
        return;
    }

    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!"
              << std::endl;
    energyPoints--;
}

void ClapTrap::takeDamage(uint amount) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " can't take damage. It's already destroyed." << std::endl;
        return;
    }

    if (amount == hitPoints) {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and is destroyed!" << std::endl;
    } else {
        if (amount > hitPoints)
            hitPoints = 0;
        else
            hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage. Hit points remaining: "
                  << hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(uint amount) {
    if (hitPoints == 0 && energyPoints == 0) {
        std::cout << "ClapTrap " << name << " can't be repaired. It's destroyed." << std::endl;
        return;
    }

    hitPoints += amount;
    std::cout << "ClapTrap " << name << " is repaired for " << amount << " points. Hit points remaining: " << hitPoints
              << std::endl;
    if (energyPoints > 0)
        energyPoints--;
}
