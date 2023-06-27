//
// Created by redone on 6/25/23.
//

#ifndef POOL_BUREAUCRAT_HPP
#define POOL_BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class GradeTOOHighException : public std::exception {
public:
    virtual const char *what() const throw() {
        return "Grade is too high";
    }
};

class GradeTOOLowException : public std::exception {
public:
    virtual const char *what() const throw() {
        return "Grade is too low";
    }
};

class Bureaucrat {

private:
    const std::string &name;
    short grade;
    static short lowGrade;
    static short maxGrade;

    void checker();

public:
    Bureaucrat(const std::string &name, short grade);

    Bureaucrat(const Bureaucrat &other);

    Bureaucrat &operator=(const Bureaucrat &other);

    virtual ~Bureaucrat();

    short getGrade() const;

    const std::string &getName() const;

    Bureaucrat &operator++();

    Bureaucrat operator++(int);

    Bureaucrat &operator--();

    Bureaucrat operator--(int);
};

std::ostream &operator<<(std::ostream &, Bureaucrat &);

#endif //POOL_BUREAUCRAT_HPP
