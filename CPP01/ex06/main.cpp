//
// Created by Redouane Elkaboussi on 6/5/23.
//

#include "Harl.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Error: invalid args" << std::endl;
		return EXIT_FAILURE;
	}

	Harl harl;
	harl.complain(std::string(argv[1]));
	return 0;
}