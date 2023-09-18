#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}

Bureaucrat::Bureaucrat() : name("defualt"), grade(150) {}

Bureaucrat::Bureaucrat(Bureaucrat &object) : name(object.getName()), grade(object.getGrade()) {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& object) {
	if (this == &object)
		return *this;
	this->grade = object.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

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

void	Bureaucrat::signForm(Form& form) {
	try {
		if (form.beSigned(*this) == true)
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const& form) {
	if (this->getGrade() > form.getExecGrade()) {
		throw Bureaucrat::GradeTooLowException();
	}
	else if (form.getSigned() == false) {
		throw Form::NotSignedException();
	}
	else {
	    std::cout << this->name << " execute " << form.getName() << std::endl;
	    form.execute(*this);
	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
