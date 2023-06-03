//
// Created by Redouane Elkaboussi on 6/3/23.
//

#include "Harl.hpp"


void    Harl::debug( void ) {
	std::cout << "Debug: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info( void ) {
	std::cout << "Info: I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning( void ) {
	std::cout << "Warning: I think I deserve to have some extra bacon for free. I've been coming here for years and you just started working here last month." << std::endl;
}

void    Harl::error( void ) {
	std::cout << "Error: This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {
	void (Harl::*function[4])( void ) = {
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error,
	};
	std::string index[4] = {
			"debug",
			"info",
			"warning",
			"error"
	};
	int i = 0;
	for (; i < 4; i++) {
		if (index[i] == level)
			break ;
	}
	if (i == 4) {
		std::cerr << "invalid level" << std::endl;
		return ;
	}
	(this->*function[i])();
}
