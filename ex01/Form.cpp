#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const char	*Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

Form::Form()
: name("defualt"), sign_grade(150), exec_grade(150) {
	this->is_signed = false;
}

Form::Form(const std::string name, const int sign_grade, const int exec_grade)
: name(name), sign_grade(sign_grade), exec_grade(exec_grade) {
	if (this->getSignGrade() < 1 || this->getExecGrade() < 1)
		throw Form::GradeTooHighException();
	else if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
		throw Form::GradeTooLowException();
	this->is_signed = false;
}

Form::Form(Form &object)
: name(object.getName()), sign_grade(object.getSignGrade()), exec_grade(object.getExecGrade()) {
	*this = object;
}

Form&	Form::operator=(const Form& object) {
	if (this != &object)
		this->setSigned(object.getSigned());
	return *this;
}

Form::~Form() {}

const std::string	Form::getName() const {
	return this->name;
}

bool	Form::getSigned() const {
	return this->is_signed;
}

int	Form::getSignGrade() const {
	return this->sign_grade;
}

int	Form::getExecGrade() const {
	return this->exec_grade;
}

void	Form::setSigned(bool is_signed) {
	this->is_signed = is_signed;
}

void	Form::beSigned(Bureaucrat& b) {
	if (this->getSignGrade() < b.getGrade())
		throw Form::GradeTooLowException();
	else
		this->setSigned(true);
}

std::ostream&	operator<<(std::ostream& os, const Form& f) {
	os << std::boolalpha << f.getName()
	<< ", signed: " << f.getSigned()
	<< ", sign_grade: " << f.getSignGrade()
	<< ", execute_grade: " << f.getExecGrade();
	return os;
}
