//
// Created by redone on 6/11/23.
//

#include "ClapTrap.hpp"

int main() {
    ClapTrap clapTrap("Player");

    clapTrap.attack("Enemy");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(3);
    clapTrap.takeDamage(15);
    clapTrap.attack("Enemy");
    clapTrap.attack("Enemy");

    return 0;
}
