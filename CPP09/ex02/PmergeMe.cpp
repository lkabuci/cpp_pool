//
// Created by redone on 9/7/23.
//

#include <cmath>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::deque<int> &deque) : list(deque) {
    prepareSequences();
    insertion();
}

const std::deque<int> &PmergeMe::getDeque() const {
    return list;
}

void PmergeMe::sortDeque() {
}

void PmergeMe::prepareSequences() {
    // todo: check what condition should i break return directly whether it's 0, 1 or 2
    int smallPair = std::numeric_limits<int>::max();
    int smallPairIndex;
    if (list.size() <= 2)
        return;
    for (size_t i = 0; i < list.size() - 1; i += 2) {
        if (i + 1 > list.size())
            break;
        int smallest = list[i];
        int biggest = list[i + 1];
        if (smallest > biggest) {
            std::swap(smallest, biggest);
        }
        pairs.push_back(std::make_pair(biggest, smallest));
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), biggest);
        mainChain.insert(pos, biggest);
        if (mainChain[0] == biggest) {
            smallPair = smallest;
            smallPairIndex = (int)i;
        }
    }
    mainChain.push_front(smallPair);
    pairs.erase(pairs.begin() + smallPairIndex);
}

/* *Just for displaying* */
void PmergeMe::display_pairGroups() {
    std::cout << "paired: ";
    std::cout << "[";
    for (pair_dq::iterator it = pairs.begin(); it != pairs.end(); it++) {
        std::cout << "[" << it->first << ", " << it->second << "]";
        if (it + 1 != pairs.end()) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

void PmergeMe::display_list() {
    std::cout << "list: ";
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << list[i];
        if (i + 1 != list.size()) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

void PmergeMe::display_largest() {
    std::cout << "largest list: ";
    for (size_t i = 0; i < mainChain.size(); i++) {
        std::cout << mainChain[i];
        if (i + 1 != mainChain.size()) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

void PmergeMe::insertion() {
}
