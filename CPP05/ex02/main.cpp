//
// Created by redone on 7/6/23.
//

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    // Create a bureaucrat
    Bureaucrat bureaucrat("Bureaucrat", 50);

    // Create some forms
    ShrubberyCreationForm shrubberyForm("Garden");
    RobotomyRequestForm robotomyForm("John");
    PresidentialPardonForm pardonForm("Alice");

    // Test signing and execution
    try {
        bureaucrat.signForm(shrubberyForm);
        bureaucrat.executeForm(shrubberyForm);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        bureaucrat.signForm(robotomyForm);
        bureaucrat.executeForm(robotomyForm);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        bureaucrat.signForm(pardonForm);
        bureaucrat.executeForm(pardonForm);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
