//
// Created by redone on 7/6/23.
//

#include "PresidentialPardonForm.hpp"

// sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
    AForm("PresidentialForm", 25, 5),
    target(target)
{
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (this->getIsSigned() == false) {
        throw AForm::NotSignedException();
    }
    if (executor.getGrade() > this->getGradeRequiredToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

