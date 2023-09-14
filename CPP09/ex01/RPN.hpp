//
// Created by redone on 9/7/23.
//

#ifndef POOL_RPN_HPP
#define POOL_RPN_HPP

#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstdlib>

class RPN {

public:
    explicit RPN(const char* args);
    void displayResult();

private:
    std::stack<int> stack;
    std::queue<std::string>  queue;
};


#endif //POOL_RPN_HPP
