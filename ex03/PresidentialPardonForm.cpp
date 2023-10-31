#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("PresidentialPardonForm", target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& object)
: AForm("PresidentialPardonForm", object.getTarget(), 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > getExecGrade()) {
		throw GradeTooLowException();
	}
	else if (getSigned() == false) {
		throw NotSignedException();
	}

	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
