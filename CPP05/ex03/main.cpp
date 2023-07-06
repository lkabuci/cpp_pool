//
// Created by redone on 7/6/23.
//

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    delete rrf;
}
