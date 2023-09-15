#include "Bureaucrat.hpp"
#include <iostream>

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}

Bureaucrat::Bureaucrat() : name("defualt") {
	grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &object) {
	*this = object;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& object) {
	if (this != &object) {
		this->grade = object.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string	Bureaucrat::getName() const {
	return this->name;
}

int	Bureaucrat::getGrade() const {
	return this->grade;
}

void	Bureaucrat::increaseGrade() {
	if (this->grade == 1)
		std::cout << "Grade is already highest. Grade: " << std::endl;
	else {
		--this->grade;
		std::cout << "Grade is increased. Grade: " << this->grade << std::endl;
	}
}

void	Bureaucrat::decreaseGrade() {
	if (this->grade == 150)
		std::cout << "Grade is already lowest. Grade: " << this->grade << std::endl;
	else {
		++this->grade;
		std::cout << "Grade is decreased. Grade: " << this->grade << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
