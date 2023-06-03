//
// Created by Redouane Elkaboussi on 6/3/23.
//

#ifndef POOL_HARL_HPP
#define POOL_HARL_HPP

#include <string>
#include <cstdlib>
#include <iostream>


class Harl {
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:
	void complain( std::string level );
};

#endif //POOL_HARL_HPP
