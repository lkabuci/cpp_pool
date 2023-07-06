//
// Created by redone on 7/6/23.
//

#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
    AForm("Robotomy request", 72, 45),
    target(target)
{
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (this->getIsSigned() == false) {
        throw AForm::NotSignedException();
    }
    if (executor.getGrade() > this->getGradeRequiredToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << "Some drilling noises" << std::endl;
    std::srand(time(NULL));
    if (std::rand() & 1) {
        std::cout << target << " has been robotomized successfully" << std::endl;
    }
    else {
        std::cout << target << " robotomy failed" << std::endl;
    }

}

