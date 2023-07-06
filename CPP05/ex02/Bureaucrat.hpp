//
// Created by redone on 6/25/23.
//

#ifndef CPP05_EX00_BUREAUCRAT_HPP
#define CPP05_EX00_BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#include "AForm.hpp"

class AForm;

class Bureaucrat {

private:
    const std::string name;
    short grade;
    static short lowGrade;
    static short maxGrade;

public:
    Bureaucrat();

    Bureaucrat(const std::string name, short grade);

    Bureaucrat(const Bureaucrat &);

    Bureaucrat &operator=(const Bureaucrat &);

    virtual ~Bureaucrat();

    short getGrade() const;

    std::string getName() const;

    void promotion();

    void demotion();

    void signForm(AForm&);

    void executeForm(AForm const & form);

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &, Bureaucrat &);

#endif
