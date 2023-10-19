//
// Created by redone on 7/14/23.
//

#ifndef POOL_ITER_HPP
#define POOL_ITER_HPP

#include <iostream>

template<typename T, typename V>
void iter(T *array, int length, V *func) {
    if (array == NULL) {
        return;
    }
    for (int i = 0; i < length; ++i) {
        func(array[i]);
    }
};

#endif //POOL_ITER_HPP
