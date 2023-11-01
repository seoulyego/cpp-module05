#include "Form.hpp"
#include <iostream>

Form::Form(const std::string& name, const int sign_grade, const int exec_grade)
: _name(name), _isSigned(false), _signGrade(sign_grade), _execGrade(exec_grade) {
	if (_signGrade < 1 || _execGrade < 1) {
		throw Form::GradeTooHighException();
	}
	else if (_signGrade > 150 || _execGrade > 150) {
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
	if (_signGrade < b.getGrade()) {
		throw GradeTooLowException();
	}
	else if (_isSigned == true) {
		std::cout << _name << " is already signed." << std::endl;
	}
	else {
		_isSigned = true;
		std::cout << b.getName() << " signed " << _name << std::endl;
	}
}

const char *Form::GradeTooHighException::what() const throw() { return "Grade is too high."; }

const char *Form::GradeTooLowException::what() const throw() { return "Grade is too low."; }

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << std::boolalpha << f.getName()
	<< ", signed: " << f.getSigned()
	<< ", sign_grade: " << f.getSignGrade()
	<< ", execute_grade: " << f.getExecGrade();
	return os;
}
