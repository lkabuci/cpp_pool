//
// Created by Redouane Elkaboussi on 6/5/23.
//

#include "Harl.hpp"

void    Harl::debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}

void    Harl::info( void ) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "Info: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void    Harl::warning( void ) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "Warning: I think I deserve to have some extra bacon for free. I've been coming here for years and you just started working here last month." << std::endl << std::endl;
}

void    Harl::error( void ) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "Error: This is unacceptable, I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::somethigElse(void) {
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
}

void	Harl::complain(std::string level) {
	enum index {
		DEBUG = 0,
		INFO,
		WARNING,
		ERROR,
		ELSE
	};
	std::string index[4] = {
			"DEBUG",
			"INFO",
			"WARNING",
			"ERROR"
	};
	int i = 0;
	for (; i < 4; i++) {
		if (index[i] == level)
			break ;
	}
	if (i == ELSE) {
		this->somethigElse();
		return ;
	}
	switch (i) {
		case DEBUG:
			this->debug();
		case INFO:
			this->info();
		case WARNING:
			this->warning();
		case ERROR:
			this->error();
	}
}
