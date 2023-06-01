#include "Zombie.hpp"

Zombie* newZombie(const std::string& name) {
	Zombie*	newOne = new Zombie();
	newOne->setName(name);
	return (newOne);
}
