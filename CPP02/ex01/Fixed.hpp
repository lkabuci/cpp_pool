//
// Created by Redouane Elkaboussi on 6/6/23.
//

#ifndef POOL_FIXED_HPP
#define POOL_FIXED_HPP

#include <iostream>
#include <fstream>

class Fixed {
public:
	Fixed ( void );
	Fixed (const Fixed &obj);
	Fixed (const int value);
	Fixed (const float value);
	Fixed& operator=(const Fixed& other);
	~Fixed( void );

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;

private:
	int					value;
	static const int	fractionalBits;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif //POOL_FIXED_HPP
