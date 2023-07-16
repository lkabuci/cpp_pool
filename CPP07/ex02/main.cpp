//
// Created by redone on 7/14/23.
//

#include "Array.hpp"

void foo() {
//    void* ptr = std::malloc(15);
//    (void)ptr;
}

int main() {
    Array<int> emptyArray;
    std::cout << "Empty Array Size: " << emptyArray.size() << std::endl;

    // Create an array with 5 elements
    Array<int> intArray(5);
    std::cout << "Initial Array Size: " << intArray.size() << std::endl;

    // Access and modify elements
    intArray[0] = 10;
    intArray[1] = 20;
    intArray[2] = 30;
    intArray[3] = 40;
    intArray[4] = 50;

    std::cout << "Array Elements: ";
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // Test copy constructor and assignment operator
    Array<int> copyArray(intArray);
    Array<int> assignedArray;
    assignedArray = intArray;

    std::cout << "Copied Array Elements: ";
    for (unsigned int i = 0; i < copyArray.size(); ++i) {
        std::cout << copyArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Assigned Array Elements: ";
    for (unsigned int i = 0; i < assignedArray.size(); ++i) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

