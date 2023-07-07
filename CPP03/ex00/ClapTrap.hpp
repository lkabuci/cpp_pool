//
// Created by redone on 6/11/23.
//

#ifndef POOL_CLAPTRAP_HPP
#define POOL_CLAPTRAP_HPP

#include <iostream>
#include <string>

typedef unsigned int uint;

class ClapTrap {
private:
    const std::string name;
    uint hitPoints;
    uint energyPoints;
    uint attackDamage;

public:
	ClapTrap();
	ClapTrap(const ClapTrap& clapTrap);
	ClapTrap& operator=(const ClapTrap& clapTrap);

    explicit ClapTrap(const std::string &name);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(uint amount);
    void beRepaired(uint amount);
};


#endif //POOL_CLAPTRAP_HPP
