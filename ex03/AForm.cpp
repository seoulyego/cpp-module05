#include "AForm.hpp"
#include <iostream>

const char *AForm::GradeTooHighException::what() const throw() { return "Grade is too high."; }

const char *AForm::GradeTooLowException::what() const throw() { return "Grade is too low."; }

const char *AForm::NotSignedException::what() const throw() { return "Must be signed before excute."; }

AForm::AForm(const std::string& name, const std::string& target, const int signGrade, const int execGrade)
: _name(name), _target(target), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (getSignGrade() < 1 || getExecGrade() < 1) {
		throw GradeTooHighException();
	}
	else if (getSignGrade() > 150 || getExecGrade() > 150) {
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

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << std::boolalpha << f.getName()
	<< ", signed: " << f.getSigned()
	<< ", sign_grade: " << f.getSignGrade()
	<< ", execute_grade: " << f.getExecGrade();
	return os;
}
