#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Weapon {

private:
    std::string _type;

public:
	Weapon();
    Weapon(std::string _type);
    ~Weapon();
    const std::string& getType( void );
    void setType(std::string newType);
};

#endif // WEAPON_HPP