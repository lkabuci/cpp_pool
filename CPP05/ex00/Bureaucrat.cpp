//
// Created by redone on 6/25/23.
//

#include "Bureaucrat.hpp"

short Bureaucrat::lowGrade = 150;
short Bureaucrat::maxGrade = 1;

Bureaucrat::Bureaucrat(const std::string& name, short grade) : name(name) {
    this->grade = grade;
    checker();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this == &other)
        return *this;
    const_cast<std::string&>(name) = other.name;
    grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
}

const std::string &Bureaucrat::getName() const {
    return name;
}

short Bureaucrat::getGrade() const {
    return grade;
}

Bureaucrat &Bureaucrat::operator++() {
    this->grade--;
    checker();
    return *this;
}

Bureaucrat Bureaucrat::operator++(int) {
    Bureaucrat tmp = *this;
    this->grade--;
    checker();
    return tmp;
}

Bureaucrat &Bureaucrat::operator--() {
    this->grade++;
    checker();
    return *this;
}

Bureaucrat Bureaucrat::operator--(int) {
    Bureaucrat tmp = *this;
    this->grade++;
    checker();
    return tmp;
}

void Bureaucrat::checker() {
    if (grade < Bureaucrat::maxGrade)
        throw GradeTOOHighException();
    else if (grade > Bureaucrat::lowGrade)
        throw GradeTOOLowException();
}

std::ostream& operator<<(std::ostream &os, Bureaucrat &bureaucrat) {
    os  << bureaucrat.getName()
        << ", bureaucrat grade "
        << bureaucrat.getGrade()
        << "."
        << std::endl;
    return os;
}
