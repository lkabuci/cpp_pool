//
// Created by redone on 6/10/23.
//

#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    Point a (10, 5);
    Point b (30, 20);
    Point c (14, 20);
    std::cout << (bool)bsp(a, b, c, Point(20, 13)) << std::endl;
    std::cout << (bool)bsp(a, b, c, Point(200, 130)) << std::endl;
    return 0;
}
