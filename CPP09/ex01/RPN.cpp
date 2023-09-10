//
// Created by redone on 9/7/23.
//

#include "RPN.hpp"

static std::queue<std::string> getQueue(const char *);

static bool isElementValid(std::string basicString);

static bool isOperand(std::string &str);

static void operate(std::stack<int> &, char);

static int getResult(int v1, int v2, char op);

RPN::RPN(const char *args) {
    queue = getQueue(args);
    while (!queue.empty()) {
        if (!isOperand(queue.front())) {
            stack.push(atoi(queue.front().c_str()));
        } else {
            operate(stack, queue.front()[0]);
        }
        queue.pop();
    }
    if (stack.size() != 1) {
        std::cerr << "Error: more than one operands left on the stack" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << stack.top() << std::endl;
}

void RPN::displayResult() {
    std::stack<int> tmp = stack;
    while (!stack.empty()) {
        stack.pop();
    }
    stack = tmp;
}

static void operate(std::stack<int> &stack, char op) {
    if (stack.size() < 2) {
        std::cerr << "Error: the stack is empty for another operation" << std::endl;
        exit(EXIT_FAILURE);
    }
    int v1 = stack.top();
    stack.pop();
    int v2 = stack.top();
    stack.pop();
    int res = getResult(v1, v2, op);
    stack.push(res);
}

static int getResult(int v1, int v2, char op) {
    if (op == '+')
        return v1 + v2;
    if (op == '-')
        return v2 - v1;
    if (op == '*')
        return v1 * v2;
    else
        return v2 / v1;
}

static std::queue<std::string> getQueue(const char *s) {
    std::string str(s);
    std::stringstream ss(str);
    std::string element;
    std::queue<std::string> queue;
    while (std::getline(ss, element, ' ')) {
        if (!isElementValid(element)) {
            std::cerr << "Error: invalid element " << element << std::endl;
            exit(EXIT_FAILURE);
        }
        queue.push(element);
    }
    return queue;
}

static bool isElementValid(std::string basicString) {
    if (basicString.length() != 1) {
        return false;
    }
    if (isOperand(basicString)) {
        return true;
    }
    std::stringstream ss(basicString);
    int value;
    ss >> value;
    if (ss.fail()) {
        return false;
    }
    return true;
}

static bool isOperand(std::string &str) {
    return std::string("+-*/").find(str[0]) != std::string::npos;
}
