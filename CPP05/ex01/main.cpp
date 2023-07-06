//
// Created by redone on 6/25/23.
//

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat mqadem("mqadem", 10);
        Form form("Chahadat l7ayat", 60, 75);

        std::cout << form << std::endl;
        mqadem.signForm(form);

        Bureaucrat stager("Stager", 150);
        stager.signForm(form);

        std::cout << form << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
