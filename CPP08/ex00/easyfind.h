//
// Created by winston on 8/28/23.
//

#ifndef POOL_EASYFIND_H
#define POOL_EASYFIND_H

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iostream>

template<typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Runtime Error: value not found in the container");
    }
    return it;
}

#endif //POOL_EASYFIND_H
