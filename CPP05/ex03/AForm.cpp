//
// Created by redone on 6/27/23.
//

#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const AForm &other)
        : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
          gradeToExecute(other.gradeToExecute) {
}

AForm &AForm::operator=(const AForm &other) {
    if (this == &other)
        return *this;
    const_cast<std::string &>(name) = other.name;
    isSigned = other.isSigned;
    const_cast<int &>(gradeToSign) = other.gradeToSign;
    const_cast<int &>(gradeToExecute) = other.gradeToExecute;
    return *this;
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute)
        : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::~AForm() {}

std::string AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeRequiredToSign() const {
    return gradeToSign;
}

int AForm::getGradeRequiredToExecute() const {
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << "Form: " << form.getName()
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade Required to Sign: " << form.getGradeRequiredToSign()
       << ", Grade Required to Execute: " << form.getGradeRequiredToExecute();
    return os;
}

const char *AForm::NotSignedException::what() const throw() {
    return "Form not signed";
}

const char *AForm::FileOpenException::what() const throw() {
    return "File can't be created";
}
