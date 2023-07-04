//
// Created by redone on 6/27/23.
//

#include "Form.hpp"

Form::Form(const std::string& name, int gradeRequiredToSign, int gradeRequiredToExecute)
    : name(name), isSigned(false), gradeRequiredToSign(gradeRequiredToSign),
      gradeRequiredToExecute(gradeRequiredToExecute) {
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
        throw GradeTooHighException();
    else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
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
    return gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const {
    return gradeRequiredToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= gradeRequiredToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.getName()
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade Required to Sign: " << form.getGradeRequiredToSign()
       << ", Grade Required to Execute: " << form.getGradeRequiredToExecute();
    return os;
}
