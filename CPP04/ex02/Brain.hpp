//
// Created by redone on 6/18/23.
//

#ifndef POOL_BRAIN_HPP
#define POOL_BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
protected:
    std::string ideas[100];

public:
    Brain();

    virtual ~Brain();

    Brain(const Brain &);

    Brain &operator=(const Brain &);
};


#endif //POOL_BRAIN_HPP
