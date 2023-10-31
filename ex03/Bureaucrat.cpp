#include "AForm.hpp"
#include <iostream>

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Grade is too high."; }

const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Grade is too low."; }

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	else if (grade > 150) {
		throw GradeTooLowException();
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

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
	} catch (std::exception& e) {
		std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form) {
	try {
		form.execute(*this);
	} catch (std::exception& e) {
		std::cout << getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
