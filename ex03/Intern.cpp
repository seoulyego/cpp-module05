#include "Intern.hpp"
#include <iostream>

static AForm *makeShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }

static AForm *makeRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }

static AForm *makePresidential(const std::string& target) { return new PresidentialPardonForm(target); }

const char *Intern::NoFormException::what() const throw() {
	return "Does not exist name of form.";
}

Intern::Intern() {}

Intern::Intern(const Intern& object) { *this = object; }

Intern& Intern::operator=(const Intern& object) {
	if (this == &object) {
		return *this;
	}
	return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string& name, const std::string& target) {
	static AForm *(*func[3])(const std::string& target) = {
		&makeShrubbery,
		&makeRobotomy,
		&makePresidential
	};
	static std::string form[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++) {
		if (form[i] == name) {
			std::cout << "Intern creates " << target << std::endl;
			return func[i](target);
		}
	}
	throw NoFormException();
	return NULL;
}
