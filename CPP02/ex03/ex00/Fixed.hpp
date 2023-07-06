//
// Created by Redouane Elkaboussi on 6/4/23.
//

#ifndef POOL_FIXED_HPP
#define POOL_FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
public:
	Fixed ( void );							// default constructor
	Fixed (Fixed &obj);						// copy constructor
	Fixed& operator=(const Fixed& other);	// copy assignment operator
	~Fixed( void );

	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:
	int					fixedPointNumberValue;
	static const int	fractionalBits;
};

#endif //POOL_FIXED_HPP
