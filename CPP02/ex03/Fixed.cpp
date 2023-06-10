//
// Created by Redouane Elkaboussi on 6/4/23.
//

#include "Fixed.hpp"

const int Fixed::exponent = 8;

Fixed::Fixed () {
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed (const Fixed& obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed (const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->value = (value * (1 << Fixed::exponent));
}

Fixed::Fixed (const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->value = (int) (value * (1 << Fixed::exponent));
}

Fixed& Fixed::operator= (const Fixed& other) {
	this->value = other.value;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed () {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits () const {
	return this->value;
}

void Fixed::setRawBits (const int raw) {
	this->value = raw;
}

float Fixed::toFloat () const {
	return ((float) this->value / (float) (1 << Fixed::exponent));
}

int Fixed::toInt () const {
	return (this->value / (1 << Fixed::exponent));
}

bool Fixed::operator> (const Fixed& other) const {
	return this->value > other.value;
}

bool Fixed::operator< (const Fixed& other) const {
	return this->value < other.value;
}

bool Fixed::operator>= (const Fixed& other) const {
	return this->value >= other.value;
}

bool Fixed::operator<= (const Fixed& other) const {
	return this->value <= other.value;
}

bool Fixed::operator== (const Fixed& other) const {
	return this->value == other.value;
}

bool Fixed::operator!= (const Fixed& other) const {
	return this->value != other.value;
}

Fixed Fixed::operator+ (const Fixed& other) const {
	Fixed result;
	result.value = this->value + other.value;
	return result;
}

Fixed Fixed::operator- (const Fixed& other) const {
	Fixed result;
	result.value = this->value - other.value;
	return result;
}

Fixed Fixed::operator* (const Fixed& other) const {
	Fixed result;
	result.value = this->value * other.value;
	return result;
}

Fixed Fixed::operator/ (const Fixed& other) const {
	Fixed result;
	result.value = this->value / other.value;
	return result;
}

void Fixed::operator++ (void) {
	*this = *this + Fixed((int) +1);
}

Fixed Fixed::operator++ (int other) {
	Fixed res = other;
	this->operator++();
	return res;
}

void Fixed::operator-- (void) {
	*this = *this + Fixed((int) -1);
}

Fixed Fixed::operator-- (int other) {
	Fixed res = other;
	this->operator--();
	return res;
}

std::ostream& operator<< (std::ostream& stream, const Fixed& fixed) {
	stream << fixed.toFloat();
	return stream;
}
