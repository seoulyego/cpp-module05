#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& object);
		Intern& operator=(const Intern& object);
		~Intern();

		AForm *makeForm(const std::string& name, const std::string& target);

		class NoFormException : public std::exception {
			public:
				const char *what() const throw();
		};
};

#endif  // INTERN_HPP
