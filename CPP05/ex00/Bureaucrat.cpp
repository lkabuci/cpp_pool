//
// Created by redone on 6/25/23.
//

#include "Bureaucrat.hpp"

short Bureaucrat::lowGrade = 150;
short Bureaucrat::maxGrade = 1;

Bureaucrat::Bureaucrat(const std::string name, short grade) : name(name) {
    if (grade < Bureaucrat::maxGrade) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > Bureaucrat::lowGrade) {
        throw Bureaucrat::GradeTooLowException();
    } else {
        this->grade = grade;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this == &other)
        return *this;
    const_cast<std::string &>(name) = other.name;
    grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
}

std::string Bureaucrat::getName() const {
    return name;
}

short Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::promotion() {
    if (grade <= Bureaucrat::maxGrade) {
        throw Bureaucrat::GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::demotion() {
    if (grade >= Bureaucrat::lowGrade) {
        throw Bureaucrat::GradeTooLowException();
    }
    grade++;
}

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}


std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat) {
    os << bureaucrat.getName()
       << ", bureaucrat grade "
       << bureaucrat.getGrade()
       << "."
       << std::endl;
    return os;
}
