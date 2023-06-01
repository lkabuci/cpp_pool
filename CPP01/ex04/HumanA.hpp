#ifndef CPP_POOL_HUMANA_HPP
#define CPP_POOL_HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
private:
	std::string	name;
	Weapon		weapon;
public:
	HumanA(std::string name, Weapon weapon);
	~HumanA();
	void	attack(void);

};


#endif //CPP_POOL_HUMANA_HPP