//
// Created by redone on 8/28/23.
//

#include "easyfind.h"

int main(int argc, char *argv[]) {

    (void)argc, (void)argv;

    int target = 1;

    std::vector<int> vector;

    vector.push_back(3);
    vector.push_back(2);
    vector.push_back(10);
    vector.push_back(0);
    vector.push_back(5);

    try {
        std::vector<int>::iterator it = easyfind(vector, target);
        std::cout << *it << " found\n";
    }
    catch (const std::exception &exception) {
        std::cout << exception.what() << std::endl;
    }
}
