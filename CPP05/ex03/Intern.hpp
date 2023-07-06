//
// Created by redone on 7/6/23.
//

#ifndef POOL_INTERN_HPP
#define POOL_INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern {

public:
    Intern();

    Intern(const Intern &other);

    Intern &operator=(const Intern &other);

    virtual ~Intern();

    AForm* makeForm(std::string formName, std::string targetForm);
};


#endif //POOL_INTERN_HPP
