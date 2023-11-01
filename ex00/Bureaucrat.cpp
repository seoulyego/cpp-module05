#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, int grade)
: _name(name), _grade(grade) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& object)
: _name(object.getName()), _grade(object.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::increaseGrade() {
	if (_grade == 1) {
		throw GradeTooHighException();
	}
	else {
		--_grade;
		std::cout << "Grade is increased. Grade: " << _grade << std::endl;
	}
}

void Bureaucrat::decreaseGrade() {
	if (_grade == 150) {
		throw GradeTooLowException();
	}
	else {
		++_grade;
		std::cout << "Grade is decreased. Grade: " << _grade << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Grade is too high."; }

const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Grade is too low."; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
