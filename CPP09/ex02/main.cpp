//
// Created by redone on 9/7/23.
//

#include "PmergeMe.hpp"

template <typename T>
void fillContainer(T&, const char **);

int main(int argc, const char *argv[]) {

    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe {list of random numbers}." << std::endl;
        return 1;
    }
    std::deque<int> dq;
    fillContainer(dq, argv);
    PmergeMe Sdeque(dq);
    Sdeque.display_list();
    Sdeque.display_pairGroups();
    Sdeque.display_largest();

    return 0;
}

template <typename T>
void fillContainer(T& container, const char *args[]) {
    for (int i = 1; args[i]; ++ i) {
        char *pEnd;
        long v = strtol(args[i], &pEnd, 10);
        while (*pEnd && std::iswspace(*pEnd)) ++pEnd;
        if (*pEnd != 0) {
            std::cerr << "Error: invalid number: " << args[i] << std::endl;
            exit(EXIT_FAILURE);
        }
        container.push_back(v);
    }
}
