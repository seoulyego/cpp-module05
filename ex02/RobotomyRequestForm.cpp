#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
: AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& object)
: AForm("RobotomyRequestForm", 72, 45), target(object.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& object) {
	if (this == &object)
		return *this;
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
: AForm("RobotomyRequestForm", 72, 45), target(target) {}

const std::string	RobotomyRequestForm::getTarget() const {
	return this->target;
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getExecGrade()) {
		throw GradeTooLowException();
	}
	else if (this->getSigned() == false) {
		throw NotSignedException();
	}

	int	tmp = rand() % 2;

	std::cout << "Start robotomize, Rizzzzzzzzzzz!!!!" << std::endl;
	if (tmp) {
		std::cout << this->getTarget() << " has become a robot!" << std::endl;
	}
	else {
		std::cout << "Sorry... " << this->getTarget() << " failed to robotomize..." << std::endl;
	}
}
