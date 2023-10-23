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
#include <vector>
#include <limits>

typedef std::deque<std::pair<int, int> > pair_dq;
typedef std::vector<std::pair<int, int> > pair_vc;

class PmergeMe {

public:
    explicit PmergeMe(std::deque<int>& deque);
    explicit PmergeMe(std::vector<int>& vector);

    PmergeMe(const PmergeMe&);
    PmergeMe& operator=(const PmergeMe&);
    ~PmergeMe();

private:
    // Deque Container members
    pair_dq m_pairDeque;
    std::deque<int> m_listDeque;
    std::deque<int> m_mainChainDeque;
    std::deque<int> m_pendsDeque;
    std::deque<int> m_jacobSecDeque;
    void groupPairsDeque();
    void sortPairsDeque(size_t index);
    void insertionDeque();
    void getSequencesDeque();

    // Vector Container members
    pair_dq m_pairVector;
    std::vector<int> m_listVector;
    std::vector<int> m_mainChainVector;
    std::vector<int> m_pendsVector;
    std::vector<int> m_jacobSecVector;
    void groupPairsVector();
    void sortPairsVector(size_t index);
    void insertionVector();
    void getSequencesVector();

    // Common
    int m_oddNumber;
    bool    m_isVector;
};

#endif //POOL_PMERGEME_HPP
