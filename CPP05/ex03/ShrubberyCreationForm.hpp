//
// Created by redone on 7/6/23.
//

#ifndef POOL_SHRUBBERYCREATIONFORM_HPP
#define POOL_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm(const std::string target);

    virtual void execute(const Bureaucrat &executor) const;

private:
    const std::string target;
};


#endif //POOL_SHRUBBERYCREATIONFORM_HPP
