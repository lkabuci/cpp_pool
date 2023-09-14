//
// Created by redone on 9/7/23.
//

#ifndef POOL_PMERGEME_HPP
#define POOL_PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <limits>

typedef std::deque<std::pair<int, int> > pair_dq;

class PmergeMe {

public:
    explicit PmergeMe(std::deque<int> &deque);

private:


    // Deque Container members
    pair_dq m_pairDeque;
    std::deque<int>& m_listDeque;
    std::deque<int> m_mainChainDeque;
    std::deque<int> m_pendsDeque;
    std::deque<int> m_jacobSecDeque;
    void groupPairsDeque();
    void sortPairsDeque(size_t index);
    void insertionDeque();
    void getSequencesDeque();

    // List Container members


    // Common
    int m_oddNumber;
};

#endif //POOL_PMERGEME_HPP
