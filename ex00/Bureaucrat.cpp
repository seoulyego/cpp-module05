#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("defualt") {
	grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &object) {
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& object) {
	return *this;
}

Bureaucrat::~Bureaucrat() {
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}
