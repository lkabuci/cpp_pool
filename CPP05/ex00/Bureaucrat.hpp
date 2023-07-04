//
// Created by redone on 6/25/23.
//

#ifndef CPP05_EX00_BUREAUCRAT_HPP
#define CPP05_EX00_BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {

private:
    const std::string &name;
    short grade;
    static short lowGrade;
    static short maxGrade;

public:
    Bureaucrat(const std::string &name, short grade);

    Bureaucrat(const Bureaucrat &other);

    Bureaucrat &operator=(const Bureaucrat &other);

    virtual ~Bureaucrat();

    short getGrade() const;

    const std::string &getName() const;

    void promotion();

    void demotion();

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Grade too low";
        }
    };

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return "Grade too high";
        }
    };
};

std::ostream &operator<<(std::ostream &, Bureaucrat &);

#endif
