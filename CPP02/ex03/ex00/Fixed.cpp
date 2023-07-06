//
// Created by Redouane Elkaboussi on 6/4/23.
//

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

// default constructor
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->fixedPointNumberValue = 0;
}

Fixed::~Fixed() {
	std::cout << "Deconstruct called" << std::endl;
}

Fixed::Fixed(Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	fixedPointNumberValue = obj.fixedPointNumberValue;
}

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPointNumberValue = other.fixedPointNumberValue;
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointNumberValue;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointNumberValue = raw;
}
