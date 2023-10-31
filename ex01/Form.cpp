#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const char *Form::GradeTooHighException::what() const throw() { return "Grade is too high."; }

const char *Form::GradeTooLowException::what() const throw() { return "Grade is too low."; }

Form::Form(const std::string& name, const int sign_grade, const int exec_grade)
: _name(name), _isSigned(false), _signGrade(sign_grade), _execGrade(exec_grade) {
	if (getSignGrade() < 1 || getExecGrade() < 1) {
		throw Form::GradeTooHighException();
	}
	else if (getSignGrade() > 150 || getExecGrade() > 150) {
		throw Form::GradeTooLowException();
	}
}

Form::Form(const Form& object)
: _name(object.getName()), _isSigned(object.getSigned()), _signGrade(object.getSignGrade()), _execGrade(object.getExecGrade()) {}

Form::~Form() {}

const std::string& Form::getName() const { return _name; }

bool Form::getSigned() const { return _isSigned; }

int Form::getSignGrade() const { return _signGrade; }

int Form::getExecGrade() const { return _execGrade; }

void Form::beSigned(const Bureaucrat& b) {
	if (getSignGrade() < b.getGrade()) {
		throw GradeTooLowException();
	}
	else if (getSigned() == true) {
		std::cout << getName() << " is already signed." << std::endl;
	}
	else {
		_isSigned = true;
		std::cout << b.getName() << " signed " << getName() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << std::boolalpha << f.getName()
	<< ", signed: " << f.getSigned()
	<< ", sign_grade: " << f.getSignGrade()
	<< ", execute_grade: " << f.getExecGrade();
	return os;
}
