//
// Created by redone on 6/12/23.
//

#ifndef POOL_DIAMONDTRAP_HPP
#define POOL_DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string diamondName;

public:
    explicit DiamondTrap(const std::string &name);

    virtual ~DiamondTrap();

    void whoAmI();

    void attack(const std::string &target);
};

#endif //POOL_DIAMONDTRAP_HPP
