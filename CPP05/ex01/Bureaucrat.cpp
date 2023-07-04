//
// Created by redone on 6/25/23.
//

#include "Bureaucrat.hpp"

short Bureaucrat::lowGrade = 150;
short Bureaucrat::maxGrade = 1;

Bureaucrat::Bureaucrat(const std::string& name, short grade) : name(name) {
    if (grade < Bureaucrat::maxGrade) {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > Bureaucrat::lowGrade) {
        throw Bureaucrat::GradeTooLowException();
    }
    else {
        this->grade = grade;
    }
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


void Bureaucrat::promotion() {
    if (grade <= Bureaucrat::maxGrade)
        throw Bureaucrat::GradeTooHighException();
    else {
        grade --;
    }
}

void Bureaucrat::demotion() {
    if (grade >= Bureaucrat::lowGrade) {
        throw Bureaucrat::GradeTooLowException();
    }
    else {
        grade++;
    }
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream &os, Bureaucrat &bureaucrat) {
    os  << bureaucrat.getName()
        << ", bureaucrat grade "
        << bureaucrat.getGrade()
        << "."
        << std::endl;
    return os;
}
