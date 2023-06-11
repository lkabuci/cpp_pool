//
// Created by redone on 6/10/23.
//

#ifndef POOL_POINT_HPP
#define POOL_POINT_HPP

#include "Fixed.hpp"

class Point {
public:
    // Constructors
    Point();
    Point(const Point &pt);
    ~Point();
    Point &operator=(const Point &pt);
    Point(const float x, const float y);

    // Getters and Setters
    const Fixed &getA() const;
    void setA(const Fixed &a);
    const Fixed &getB() const;
    void setB(const Fixed &b);

private:
    Fixed a;
    Fixed b;
};

std::ostream& operator<<(std::ostream& os, const Point& pt);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif //POOL_POINT_HPP
