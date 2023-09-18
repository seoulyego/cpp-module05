#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
: Form("PresidentialPardonForm", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& object)
: Form("PresidentialPardonForm", 25, 5), target(object.getTarget()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&  PresidentialPardonForm::operator=(const PresidentialPardonForm& object) {
	if (this == &object)
        return *this;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
: Form("PresidentialPardonForm", 25, 5), target(target) {}

const std::string   PresidentialPardonForm::getTarget() const {
    return this->target;
}

void    PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
