//
// Created by redone on 7/14/23.
//

#include "iter.hpp"

static void    print(int nbr);

int main() {

    int array[] = {0, 1, 2, 3, 4};

    iter(array, 5, print);

    return 0;
}

static void    print(int nbr) {
    std::cout << nbr << std::endl;
}
