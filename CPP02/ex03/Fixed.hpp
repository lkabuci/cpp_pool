//
// Created by Redouane Elkaboussi on 6/4/23.
//

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed {
public:
	// Constructors
	Fixed (void);
	Fixed (const Fixed& obj);
	Fixed (const int value);
	Fixed (const float value);
	Fixed& operator= (const Fixed& other);
	~Fixed (void);

	// Overloading comparison operations
	bool operator> (const Fixed& other) const;
	bool operator< (const Fixed& other) const;
	bool operator>= (const Fixed& other) const;
	bool operator<= (const Fixed& other) const;
	bool operator== (const Fixed& other) const;
	bool operator!= (const Fixed& other) const;

	// Overloading arithmetic operators
	Fixed operator+ (const Fixed& other) const;
	Fixed operator- (const Fixed& other) const;
	Fixed operator* (const Fixed& other) const;
	Fixed operator/ (const Fixed& other) const;

	// Overloading increment and decrement operators
	void operator++ (void);            // pre incremental
	Fixed operator++ (int other);        // post incremental
	void operator-- (void);            // pre decremental
	Fixed operator-- (int other);        // post decremental


	int getRawBits (void) const;
	void setRawBits (int const raw);

	float toFloat (void) const;
	int toInt (void) const;

private:
	int value;
	static const int exponent;
};

std::ostream& operator<< (std::ostream& stream, const Fixed& fixed);

#endif //FIXED_HPP
