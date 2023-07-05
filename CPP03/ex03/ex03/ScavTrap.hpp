//
// Created by redone on 6/12/23.
//

#ifndef POOL_SCAVTRAP_HPP
#define POOL_SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

public:

    static const int EnergyPoints = 50;

    // Canonical form
    ScavTrap();
    ScavTrap(const ScavTrap& scavTrap);
    ScavTrap& operator=(const ScavTrap& scavTrap);
    ~ScavTrap();

    ScavTrap(const std::string& name);
    void guardGate();

};


#endif //POOL_SCAVTRAP_HPP
