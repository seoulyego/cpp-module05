#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
: AForm("PresidentialPardonForm", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& object)
: AForm("PresidentialPardonForm", 25, 5), target(object.getTarget()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&  PresidentialPardonForm::operator=(const PresidentialPardonForm& object) {
	if (this == &object)
		return *this;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
: AForm("PresidentialPardonForm", 25, 5), target(target) {}

const std::string	PresidentialPardonForm::getTarget() const {
	return this->target;
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getExecGrade()) {
		throw GradeTooLowException();
	}
	else if (this->getSigned() == false) {
		throw NotSignedException();
	}

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
