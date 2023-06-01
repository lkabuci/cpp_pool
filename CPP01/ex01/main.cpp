#include "Zombie.hpp"

int main() {
	Zombie *zombies = zombieHorde(3, "xx");
	delete[] zombies;
	return 0;
}
