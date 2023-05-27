#ifndef CPP_POOL_ZOMBIE_HPP
#define CPP_POOL_ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
	std::string _name;

public:
	Zombie();
	~Zombie();
	void announce(void);
	void setName(std::string name);
};

Zombie*	zombieHorde( int N, std::string name );

#endif //CPP_POOL_ZOMBIE_HPP
