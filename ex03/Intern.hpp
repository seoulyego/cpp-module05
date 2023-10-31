#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
#include <exception>

class Intern {
	public:
		class NoFormException : public std::exception {
			const char *what() const throw();
		};

		Intern();
		Intern(const Intern& object);
		Intern& operator=(const Intern& object);
		~Intern();

		AForm *makeForm(const std::string& name, const std::string& target);
};

#endif  // INTERN_HPP
