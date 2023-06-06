//
// Created by Redouane Elkaboussi on 6/6/23.
//

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = other.value;
	return *this;
}

Fixed::Fixed (const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->value = value << this->fractionalBits;
}

Fixed::Fixed (const float value) {
	this->value = value * (1 << this->fractionalBits);
	std::cout << "Float constructor called" << std::endl;
}


int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float Fixed::toFloat( void ) const {
	return this->value / (float)(1 << this->fractionalBits);
}

int Fixed::toInt( void ) const {
	return this->value >> this->fractionalBits;
}

std::ostream& operator<<(std::ostream& stream,const Fixed& fixed) {
	stream << fixed.toFloat();
	return stream;
}
