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
	void announce();
	void setName(const std::string& name);
};

Zombie*	zombieHorde( int N, const std::string& name );

#endif //CPP_POOL_ZOMBIE_HPP
