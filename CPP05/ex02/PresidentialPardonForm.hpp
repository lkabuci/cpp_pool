//
// Created by redone on 7/6/23.
//

#ifndef POOL_PRESIDENTIALPARDONFORM_HPP
#define POOL_PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    const std::string target;

public:
    PresidentialPardonForm(const std::string target);

    virtual void execute(const Bureaucrat &executor) const;
};


#endif //POOL_PRESIDENTIALPARDONFORM_HPP
