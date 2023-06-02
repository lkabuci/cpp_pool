#include "Zombie.hpp"

int	main() {
	std::string zombie1 = "zombie1";
	std::string zombie2 = "zombie2";
	std::string zombie3 = "zombie3";

	std::string zombie0 = "zombie 0";

	Zombie *zombie = newZombie(zombie0);
	zombie->announce();

	randomChump(zombie1);
	randomChump(zombie2);
	randomChump(zombie3);

	delete zombie;
	return 0;
}
