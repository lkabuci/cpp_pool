#include "Zombie.hpp"

int main(void) {
	Zombie *zombies = zombieHorde(3, "xx");
	delete[] zombies;
	return 0;
}
