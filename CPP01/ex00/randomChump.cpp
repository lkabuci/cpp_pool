#include "Zombie.hpp"

void randomChump(std::string& name) {
	Zombie randomZombie;
	randomZombie.setName(name);
	randomZombie.announce();
}
