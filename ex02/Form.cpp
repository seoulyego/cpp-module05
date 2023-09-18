#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const char	*Form::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}

const char	*Form::NotSignedException::what() const throw() {
	return "Must be signed before excute.";
}

Form::Form()
: name("defualt"), is_signed(false), sign_grade(150), exec_grade(150) {}

Form::Form(Form &object)
: name(object.getName()), is_signed(object.getSigned()), sign_grade(object.getSignGrade()), exec_grade(object.getExecGrade()) {}

Form&	Form::operator=(const Form& object) {
	if (this == &object)
		return *this;
	return *this;
}

Form::~Form() {}

Form::Form(const std::string name, const int sign_grade, const int exec_grade)
: name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade) {
	if (this->getSignGrade() < 1 || this->getExecGrade() < 1)
		throw Form::GradeTooHighException();
	else if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
		throw Form::GradeTooLowException();
}

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

bool	Form::beSigned(Bureaucrat& b) {
	if (this->getSignGrade() < b.getGrade())
		throw Form::GradeTooLowException();
	else if (this->getSigned() == true) {
		std::cout << this->getName() << " is already signed." << std::endl;
		return false;
	}
	else {
		this->setSigned(true);
		return true;
	}
}

std::ostream&	operator<<(std::ostream& os, const Form& f) {
	os << std::boolalpha << f.getName()
	<< ", signed: " << f.getSigned()
	<< ", sign_grade: " << f.getSignGrade()
	<< ", execute_grade: " << f.getExecGrade();
	return os;
}
