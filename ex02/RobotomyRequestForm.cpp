#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& object)
: AForm("RobotomyRequestForm", 72, 45), target(object.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string& RobotomyRequestForm::getTarget() const {
	return this->target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->getExecGrade()) {
		throw GradeTooLowException();
	}
	else if (this->getSigned() == false) {
		throw NotSignedException();
	}

	std::srand(std::time(0));
	int	tmp = std::rand() % 2;

	std::cout << "Start robotomize, Rizzzzzzzzzzz!!!!" << std::endl;
	if (tmp) {
		std::cout << this->getTarget() << " has become a robot!" << std::endl;
	}
	else {
		std::cout << "Sorry... " << this->getTarget() << " failed to robotomize..." << std::endl;
	}
}
