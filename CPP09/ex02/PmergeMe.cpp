//
// Created by redone on 9/7/23.
//

#include <cstdio>
#include "PmergeMe.hpp"


static int computeJacobstal(size_t n, std::deque<int> &jacobstalNumbers);

static std::deque<int> generateJacobstalInsertionOrder(size_t size);

PmergeMe::PmergeMe(std::deque<int> &deque) : m_listDeque(deque), m_oddNumber(-1) {
    groupPairsDeque();
    sortPairsDeque(m_pairDeque.size());
    getSequencesDeque();
    m_jacobSecDeque = generateJacobstalInsertionOrder(m_listDeque.size() / 2);
    insertionDeque();
    deque = m_mainChainDeque;
}

void PmergeMe::groupPairsDeque() {
    if (m_listDeque.size() < 2)
        return;
    if (m_listDeque.size() & 1) {
        m_oddNumber = *(m_listDeque.end() - 1);
        m_listDeque.erase(m_listDeque.end() - 1);
    }
    for (size_t i = 0; i < m_listDeque.size() - 1; i += 2) {
        int smallest = m_listDeque[i];
        int biggest = m_listDeque[i + 1];
        if (smallest > biggest) {
            std::swap(smallest, biggest);
        }
        m_pairDeque.push_back(std::make_pair(biggest, smallest));
    }
}

void PmergeMe::insertionDeque() {
    for (std::deque<int>::iterator it = m_jacobSecDeque.begin(); it != m_jacobSecDeque.end(); it++) {
        std::deque<int>::iterator pos = std::lower_bound(m_mainChainDeque.begin(), m_mainChainDeque.end(), m_pendsDeque[*it - 2]);
        m_mainChainDeque.insert(pos, m_pendsDeque[*it - 2]);
    }
    if (m_oddNumber != -1) {
        std::deque<int>::iterator pos = std::lower_bound(m_mainChainDeque.begin(), m_mainChainDeque.end(), m_oddNumber);
        m_mainChainDeque.insert(pos, m_oddNumber);
    }
}

void PmergeMe::sortPairsDeque(size_t index) {
    if (index < 2)
        return;
    PmergeMe::sortPairsDeque(index - 1);
    std::pair<int, int> lastNode = m_pairDeque[index - 1];
    int i = (int) index - 2;
    while (i >= 0 && m_pairDeque[i].first > lastNode.first) {
        m_pairDeque[i + 1] = m_pairDeque[i];
        i--;
    }
    m_pairDeque[i + 1] = lastNode;
}

void PmergeMe::getSequencesDeque() {
    m_mainChainDeque.push_back(m_pairDeque.begin()->second);
    m_mainChainDeque.push_back(m_pairDeque.begin()->first);
    for (pair_dq::iterator it = m_pairDeque.begin() + 1; it != m_pairDeque.end(); ++it) {
        m_mainChainDeque.push_back(it->first);
        m_pendsDeque.push_back(it->second);
    }
}

int computeJacobstal(size_t n, std::deque<int> &jacobstalNumbers) {
    if (n < jacobstalNumbers.size()) {
        return jacobstalNumbers[n];
    }
    int result = computeJacobstal(n - 1, jacobstalNumbers) + 2 * computeJacobstal(n - 2, jacobstalNumbers);
    jacobstalNumbers.push_back(result);
    return result;
}

// {0, 1, 1} are the first 3 numbers of the jacobstal serie
std::deque<int> generateJacobstalInsertionOrder(size_t size) {
    std::deque<int> series;
    std::deque<int> jacobstalNumbers;
    jacobstalNumbers.push_back(0);
    jacobstalNumbers.push_back(1);
    jacobstalNumbers.push_back(1);

    int i = 3;
    int lastInserted = 1;

    while (series.size() < size - 1) {
        int jacobstalNumber = computeJacobstal(i, jacobstalNumbers);
        for (int j = jacobstalNumber; j > lastInserted; j--) {
            if (j > (int) size)
                continue;
            if (series.size() < size - 1)
                series.push_back(j);
            else
                break;
        }
        i++;
        lastInserted = jacobstalNumber;
    }
    return series;
}
