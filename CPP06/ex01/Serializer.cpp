//
// Created by redone on 7/12/23.
//

#include <cstdint>
#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
