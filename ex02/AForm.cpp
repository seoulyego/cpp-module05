#include "AForm.hpp"
#include <iostream>

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}

const char *AForm::NotSignedException::what() const throw() {
	return "Must be signed before excute.";
}

AForm::AForm(const std::string& name, const int sign_grade, const int exec_grade)
: name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade) {
	if (this->getSignGrade() < 1 || this->getExecGrade() < 1)
		throw AForm::GradeTooHighException();
	else if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& object)
: name(object.getName()), is_signed(object.getSigned()), sign_grade(object.getSignGrade()), exec_grade(object.getExecGrade()) {}

AForm::~AForm() {}

const std::string& AForm::getName() const {
	return this->name;
}

bool AForm::getSigned() const {
	return this->is_signed;
}

int AForm::getSignGrade() const {
	return this->sign_grade;
}

int AForm::getExecGrade() const {
	return this->exec_grade;
}

void AForm::setSigned(bool is_signed) {
	this->is_signed = is_signed;
}

void AForm::beSigned(Bureaucrat& b) {
	if (this->getSignGrade() < b.getGrade()) {
		throw AForm::GradeTooLowException();
	}
	else if (this->getSigned() == true) {
		std::cout << this->getName() << " is already signed." << std::endl;
	}
	else {
		this->setSigned(true);
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << std::boolalpha << f.getName()
	<< ", signed: " << f.getSigned()
	<< ", sign_grade: " << f.getSignGrade()
	<< ", execute_grade: " << f.getExecGrade();
	return os;
}
