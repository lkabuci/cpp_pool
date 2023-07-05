//
// Created by redone on 6/11/23.
//

#include "DiamondTrap.hpp"

int main() {

    DiamondTrap diamondTrap("Bob");
   diamondTrap.attack("Enemy");
   std::cerr < 
   diamondTrap.whoAmI();
   std::cerr << "heeere " << std::endl;
   diamondTrap.guardGate();
   diamondTrap.highFivesGuys();
   std::cerr << "-----" << std::endl;
   diamondTrap.takeDamage(10);
   diamondTrap.beRepaired(5);
   diamondTrap.attack("Enemy");

    return 0;
}
