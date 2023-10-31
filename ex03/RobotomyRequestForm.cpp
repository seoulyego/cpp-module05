#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& object)
: AForm("RobotomyRequestForm", object.getTarget(), 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > getExecGrade()) {
		throw GradeTooLowException();
	}
	else if (getSigned() == false) {
		throw NotSignedException();
	}

	std::srand(std::time(0));
	int	tmp = std::rand() % 2;

	std::cout << "Start robotomize, Rizzzzzzzzzzz!!!!" << std::endl;
	if (tmp) {
		std::cout << getTarget() << " has become a robot!" << std::endl;
	}
	else {
		std::cout << "Sorry... " << getTarget() << " failed to robotomize..." << std::endl;
	}
}
