//
// Created by redone on 7/12/23.
//

#include "Serializer.hpp"

int main() {
    Data data(42);

    uintptr_t serialized = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(serialized);

    if (deserialized == &data) {
        std::cout << "Serialization and deserialization successful. Pointers match." << std::endl;
    } else {
        std::cout << "Serialization and deserialization failed. Pointers don't match." << std::endl;
    }

    return 0;
}
