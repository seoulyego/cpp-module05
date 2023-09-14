#include "Form.hpp"
#include <iostream>

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

Form::Form() : name("defualt"), sign_grade(150), exec_grade(150) {
	is_signed = false;
}

Form::Form(const std::string name, bool is_signed, const int sign_grade, const int exec_grade) : name(name), sign_grade(sign_grade), exec_grade(exec_grade) {
	this->is_signed = is_signed;
	if (sign_grade < 1 || exec_grade < 1) {
		throw Form::GradeTooHighException();
	}
	else if (sign_grade > 150 || exec_grade > 150) {
		throw Form::GradeTooLowException();
	}
}

Form::Form(Form &object) : name(object.getName()), sign_grade(object.getSignGrade()), exec_grade(object.getExecGrade()) {
	*this = object;
}

Form&	Form::operator=(const Form& object) {
	if (this != &object) {
	}
	return *this;
}

Form::~Form() {
}

const std::string	Form::getName(void) const {
	return this->name;
}

const int	Form::getSignGrade(void) const {
	return this->sign_grade;
}

const int	Form::getExecGrade(void) const {
	return this->exec_grade;
}

void	Form::beSigned(Bureaucrat& b) {
}

std::ostream&	operator<<(std::ostream& os, const Form& object) {
	return os;
}
