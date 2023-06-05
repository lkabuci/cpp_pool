//
// Created by Redouane Elkaboussi on 6/4/23.
//

#include "Fixed.hpp"


Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Deconstruct called" << std::endl;
}

// static members are shared by all instances
// they must be initialized outside any constructor
Fixed::Fixed(Fixed &obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	fixedPointNumberValue = obj.fixedPointNumberValue;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	// TODO: body
	return 0;
}

void Fixed::setRawBits(const int raw) {
	(void)raw;
	std::cout << "in setRaws" << std::endl;
	// TODO: body
}
