#include "Zombie.hpp"

Zombie*	zombieHorde( int N, const std::string& name ) {
	Zombie* arraysOfZombies = new Zombie[N];
	for (int i = 0; i < N; i++) {
		arraysOfZombies[i].setName(name);
		arraysOfZombies[i].announce();
	}
	return arraysOfZombies;
}
