#include "Zombie.hpp"

void randomChump(std::string name) {
	Zombie*	randomZombie = newZombie(name);
	randomZombie->announce();
	delete randomZombie;
	std::cout << name << " is being destroyed" << std::endl;
}
