#ifndef HUMAN_A
#define HUMAN_A

#include "Weapon.hpp"

class HumanA {
private:
	std::string _name;
	Weapon		&_weapon;
public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();
	void attack( void );
};

#endif // HUMAN_A