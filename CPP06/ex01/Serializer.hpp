//
// Created by redone on 7/12/23.
//

#ifndef POOL_SERIALIZER_HPP
#define POOL_SERIALIZER_HPP


#include <cstdint>
#include <iostream>

struct Data {
    int value;
    explicit Data(int value) : value(value) {};
};


class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};


#endif //POOL_SERIALIZER_HPP
