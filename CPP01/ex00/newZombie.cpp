#include "Zombie.hpp"

Zombie* newZombie(std::string& name) {
	Zombie*	newOne = new Zombie();
	newOne->setName(name);
	return (newOne);
}
