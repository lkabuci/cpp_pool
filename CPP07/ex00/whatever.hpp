//
// Created by redone on 7/14/23.
//

#ifndef POOL_WHATEVER_HPP
#define POOL_WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
};

template<typename U>
U min(U a, U b) {
    return (a < b) ? a : b;
}

template<typename V>
V max(V a, V b) {
    return (a > b) ? a : b;
}

#endif //POOL_WHATEVER_HPP
