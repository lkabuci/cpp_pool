//
// Created by redone on 6/12/23.
//

#ifndef POOL_SCAVTRAP_HPP
#define POOL_SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:
    explicit ScavTrap(const std::string& name);
    ~ScavTrap();
    void guardGate();

};


#endif //POOL_SCAVTRAP_HPP
