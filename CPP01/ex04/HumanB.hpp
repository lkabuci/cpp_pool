#ifndef CPP_POOL_HUMANB_HPP
#define CPP_POOL_HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
	std::string	name;
	Weapon		weapon;
	bool		haveWeapon;
public:
	HumanB(std::string name);
	HumanB(std::string name, Weapon& weapon);
	~HumanB();
	void	attack(void);
	void	setWeapon(Weapon &weapon);
};


#endif //CPP_POOL_HUMANB_HPP