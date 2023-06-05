//
// Created by Redouane Elkaboussi on 6/4/23.
//

#ifndef POOL_FIXED_HPP
#define POOL_FIXED_HPP

#include <string>
#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed (Fixed &obj);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:
	int					fixedPointNumberValue;
	static const int	fractionalBits;

public:


};


#endif //POOL_FIXED_HPP
