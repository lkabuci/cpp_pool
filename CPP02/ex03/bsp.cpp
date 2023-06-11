//
// Created by redone on 6/10/23.
//

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    float ax, ay;
    float bx, by;
    float cx, cy;
    float px, py;

    float w1, w2;

    ax = a.getA().toFloat();
    ay = a.getB().toFloat();
    bx = b.getA().toFloat();
    by = b.getB().toFloat();
    cx = c.getA().toFloat();
    cy = c.getB().toFloat();
    px = point.getA().toFloat();
    py = point.getB().toFloat();

    w1 = ((ax * (cy - ay)) + (py - ay) * (cx - ay) - px * (cy - ay)) / ((by - ay) * (cx - ax) - (bx - ax) * (cy - ay));
    w2 = (py - ay - w1 * (by - ay)) / (cy - ay);
    std::cout << "w1: " << w1 << std::endl;
    std::cout << "w2: " << w2 << std::endl;
    return w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1;
}
