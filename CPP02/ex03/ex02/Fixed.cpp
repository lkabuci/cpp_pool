//
// Created by Redouane Elkaboussi on 6/4/23.
//

#include "Fixed.hpp"

const int Fixed::exponent = 8;

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed &obj) : value() {
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->value = (value * (1 << Fixed::exponent));
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->value = (int) (value * (1 << Fixed::exponent));
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    return this->value;
}

void Fixed::setRawBits(const int raw) {
    this->value = raw;
}

float Fixed::toFloat() const {
    return (this->value / (float) (1 << Fixed::exponent));
}

int Fixed::toInt() const {
    return this->value / (1 << Fixed::exponent);
}

bool Fixed::operator>(const Fixed &other) const {
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->value != other.value;
}

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() {
    *this = *this + Fixed(1);
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed res(*this);
    operator++();
    return res;
}

Fixed &Fixed::operator--() {
    *this = *this - Fixed(1);
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed res(*this);
    operator--();
    return res;
}

Fixed &Fixed::min(Fixed &fixedPoint1, Fixed &fixedPoint2) {
    return fixedPoint1 < fixedPoint2 ? fixedPoint1 : fixedPoint2;
}

const Fixed &Fixed::min(const Fixed &fixedPoint1, const Fixed &fixedPoint2) {
    return fixedPoint1 < fixedPoint2 ? fixedPoint1 : fixedPoint2;
}

Fixed &Fixed::max(Fixed &fixedPoint1, Fixed &fixedPoint2) {
    return fixedPoint1 > fixedPoint2 ? fixedPoint1 : fixedPoint2;
}

const Fixed &Fixed::max(const Fixed &fixedPoint1, const Fixed &fixedPoint2) {
    return fixedPoint1 > fixedPoint2 ? fixedPoint1 : fixedPoint2;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat();
    return os;
}
