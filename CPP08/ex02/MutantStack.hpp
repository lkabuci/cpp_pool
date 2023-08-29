//
// Created by redone on 8/29/23.
//

#ifndef POOL_MUTANTSTACK_HPP
#define POOL_MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {

public:
    MutantStack() : std::stack<T>() {}

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }
};

#endif //POOL_MUTANTSTACK_HPP
