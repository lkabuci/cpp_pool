//
// Created by redone on 6/10/23.
//

#include "Point.hpp"

Point::Point() {
    this->a.setRawBits(0);
    this->b.setRawBits(0);
}

Point::Point(const Point &pt) {
    *this = pt;
}

Point &Point::operator=(const Point &pt) {
    this->setA(pt.a);
    this->setB(pt.b);
    return *this;
}

Point::Point(const float x, const float y) {
    this->a.setRawBits(Fixed(x).getRawBits());
    this->b.setRawBits(Fixed(y).getRawBits());
}

Point::~Point() {
}

const Fixed &Point::getA() const {
    return a;
}

void Point::setA(const Fixed &a) {
    this->a.setRawBits(a.getRawBits());
}

const Fixed &Point::getB() const {
    return b;
}

void Point::setB(const Fixed &b) {
    this->b.setRawBits(b.getRawBits());
}

std::ostream &operator<<(std::ostream &os, const Point &pt) {
    os << "(" << pt.getA() << ", " << pt.getB() << ")";
    return os;
}
