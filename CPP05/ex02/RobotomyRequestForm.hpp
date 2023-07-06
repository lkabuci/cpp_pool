//
// Created by redone on 7/6/23.
//

#ifndef POOL_ROBOTOMYREQUESTFORM_HPP
#define POOL_ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    const std::string target;

public:
    RobotomyRequestForm(const std::string target);

    virtual void execute(const Bureaucrat &executor) const;
};


#endif //POOL_ROBOTOMYREQUESTFORM_HPP
