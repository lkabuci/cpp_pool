//
// Created by redone on 6/12/23.
//

#ifndef POOL_FRAGTRAP_HPP
#define POOL_FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
public:
    static const int HitPoints = 100;
    static const int AttackDamage = 30;

    explicit FragTrap(const std::string& name);

    FragTrap();
    FragTrap(const FragTrap& fragTrap);
    FragTrap& operator=(const FragTrap& fragTrap);
    ~FragTrap();

    void highFivesGuys();
};


#endif //POOL_FRAGTRAP_HPP
