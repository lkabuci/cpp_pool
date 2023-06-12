//
// Created by redone on 6/11/23.
//

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap scavTrap("Bob");
    scavTrap.attack("Enemy");
    scavTrap.guardGate();
    scavTrap.takeDamage(10);
    scavTrap.beRepaired(5);
    scavTrap.attack("Enemy");

    return 0;
}
