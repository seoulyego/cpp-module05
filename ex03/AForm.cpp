#include "AForm.hpp"
#include <iostream>

AForm::AForm(const std::string& name, const std::string& target, const int signGrade, const int execGrade)
: _name(name), _target(target), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (_signGrade < 1 || _execGrade < 1) {
		throw GradeTooHighException();
	}
	else if (_signGrade > 150 || _execGrade > 150) {
		throw GradeTooLowException();
	}
}

AForm::AForm(const AForm& object)
: _name(object.getName()), _target(object.getTarget()), _isSigned(object.getSigned()), _signGrade(object.getSignGrade()), _execGrade(object.getExecGrade()) {}

AForm::~AForm() {}

const std::string& AForm::getName() const { return _name; }

const std::string& AForm::getTarget() const { return _target; }

bool AForm::getSigned() const { return _isSigned; }

int AForm::getSignGrade() const { return _signGrade; }

int AForm::getExecGrade() const { return _execGrade; }

void AForm::beSigned(Bureaucrat& b) {
	if (_signGrade< b.getGrade()) {
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

const char *AForm::GradeTooHighException::what() const throw() { return "Grade is too high."; }

const char *AForm::GradeTooLowException::what() const throw() { return "Grade is too low."; }

const char *AForm::NotSignedException::what() const throw() { return "Must be signed before excute."; }

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << std::boolalpha << f.getName()
	<< ", signed: " << f.getSigned()
	<< ", sign_grade: " << f.getSignGrade()
	<< ", execute_grade: " << f.getExecGrade();
	return os;
}
