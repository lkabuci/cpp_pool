#ifndef CPP_POOL_WEAPON_HPP
#define CPP_POOL_WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
private:
	std::string	type;
public:
	Weapon();
	Weapon(std::string name);
	~Weapon();
	const std::string	getType(void) const;
	void				setType(std::string type);
};

#endif //CPP_POOL_WEAPON_HPP