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

    const std::deque<int> &getDeque() const;

    void sortDeque();

    /* displaying */
    void display_pairGroups();
    void display_list();
    void display_largest();

private:
    std::deque<int> list;
    pair_dq pairs;
    std::deque<int> mainChain;
    void prepareSequences();
    void insertion();

};

#endif //POOL_PMERGEME_HPP
