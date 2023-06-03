//
// Created by Redouane Elkaboussi on 6/2/23.
//

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
	std::string	_name;
	Weapon		*_weapon;
	bool		_isWeapon;

public:
	HumanB(std::string name);
	~HumanB();
	void		setName(std::string newName);
	void		setWeapon(Weapon &weapon);

	std::string getName( void );

	void		attack( void );
};

#endif //HUMANB_HPP
