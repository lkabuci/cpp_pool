//
// Created by Redouane Elkaboussi on 6/5/23.
//

#ifndef POOL_HARL_HPP
#define POOL_HARL_HPP

#include <iostream>
#include <string>

class Harl {

private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void somethigElse ( void );

public:
	void complain( std::string level );
};


#endif //POOL_HARL_HPP
