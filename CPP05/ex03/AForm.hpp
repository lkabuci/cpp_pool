//
// Created by redone on 6/27/23.
//

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    AForm();

    AForm(const AForm &);

    AForm &operator=(const AForm &);

    virtual ~AForm();

    AForm(const std::string name, int gradeToSign, int gradeToExecute);

    std::string getName() const;

    bool getIsSigned() const;

    int getGradeRequiredToSign() const;

    int getGradeRequiredToExecute() const;

    void beSigned(const Bureaucrat &bureaucrat);

    virtual void execute(Bureaucrat const & executor) const = 0;

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw();
    };

    class NotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FileOpenException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
