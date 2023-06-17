//
// Created by redone on 6/12/23.
//

#ifndef POOL_FRAGTRAP_HPP
#define POOL_FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
    explicit FragTrap(const std::string &name);

    ~FragTrap();

    void highFivesGuys();
};


#endif //POOL_FRAGTRAP_HPP
