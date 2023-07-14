//
// Created by redone on 7/14/23.
//

#ifndef POOL_ITER_HPP
#define POOL_ITER_HPP

#include <iostream>

template<typename T, typename U, typename V>

void iter(T *array, U length, V *func) {
    if (array == NULL) {
        return;
    }
    for (U i = 0; i < length; ++i) {
        func(array[i]);
    }
};

#endif //POOL_ITER_HPP
