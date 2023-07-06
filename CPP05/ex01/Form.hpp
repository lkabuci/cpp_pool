//
// Created by redone on 6/27/23.
//

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    Form();

    Form(const Form &);

    Form &operator=(const Form &);

    ~Form();

    Form(const std::string name, int gradeToSign, int gradeToExecute);

    std::string getName() const;

    bool getIsSigned() const;

    int getGradeRequiredToSign() const;

    int getGradeRequiredToExecute() const;

    void beSigned(const Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
