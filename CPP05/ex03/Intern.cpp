//
// Created by redone on 7/6/23.
//

#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    (void) other;
    return *this;
}

Intern::~Intern() {
}

AForm *Intern::makeForm(std::string formName, std::string targetForm) {
    std::string forms[] = {
            "shrubbery form",
            "robotomy request",
            "presidential pardon",
    };
    int targetIndex = 0;
    for (; targetIndex < 3; targetIndex++) {
        if (formName == forms[targetIndex]) {
            break;
        }
    }
    if (targetIndex == 3) {
        std::cerr << "Intern couldn't find " << formName << " form." << std::endl;
        return NULL;
    }
    std::cout << "Intern creates " << formName << std::endl;
    switch (targetIndex) {
        case 0:return new ShrubberyCreationForm(targetForm); break;
        case 1: return new RobotomyRequestForm(targetForm); break;
        case 2: return new PresidentialPardonForm(targetForm); break;
    }
    return NULL;
}
