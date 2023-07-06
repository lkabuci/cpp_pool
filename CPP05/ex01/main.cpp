//
// Created by redone on 6/25/23.
//

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        // Create a bureaucrat and a form
        Bureaucrat bureaucrat("John Doe", 50);
        Form form("Application Form", 60, 75);

        // Print the bureaucrat and the form
        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        // Attempt to sign the form with the bureaucrat
        bureaucrat.signForm(form);

        // Print the updated form
        std::cout << form << std::endl;

        // Increment the bureaucrat's grade and try signing the form again
        bureaucrat.promotion();
        bureaucrat.signForm(form);

        // Print the updated form
        std::cout << form << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
