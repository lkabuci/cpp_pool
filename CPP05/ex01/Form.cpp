//
// Created by redone on 6/27/23.
//

#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(const Form &other)
        : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
          gradeToExecute(other.gradeToExecute) {
}

Form &Form::operator=(const Form &other) {
    if (this == &other)
        return *this;
    const_cast<std::string &>(name) = other.name;
    isSigned = other.isSigned;
    const_cast<int &>(gradeToSign) = other.gradeToSign;
    const_cast<int &>(gradeToExecute) = other.gradeToExecute;
    return *this;
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
        : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::~Form() {}

std::string Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getGradeRequiredToSign() const {
    return gradeToSign;
}

int Form::getGradeRequiredToExecute() const {
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign)
        throw Form::GradeTooLowException();
    isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form: " << form.getName()
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade Required to Sign: " << form.getGradeRequiredToSign()
       << ", Grade Required to Execute: " << form.getGradeRequiredToExecute();
    return os;
}
