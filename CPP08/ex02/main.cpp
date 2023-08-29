//
// Created by redone on 8/29/23.
//

#include "MutantStack.hpp"
#include <iostream>

int main() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << "the top of the stack is: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "size of the stack is: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
    return 0;
}
