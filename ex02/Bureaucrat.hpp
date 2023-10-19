#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <string>

class AForm;

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;

	public:
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		Bureaucrat();
		Bureaucrat(const Bureaucrat& object);
		Bureaucrat&	operator=(const Bureaucrat& object);
		~Bureaucrat();

		Bureaucrat(const std::string name, int grade);
		const std::string	getName() const;
		int					getGrade() const;
		void				increaseGrade();
		void				decreaseGrade();
		void				signForm(AForm& form);
		void				executeForm(const AForm& form);
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

#endif  // BUREAUCRAT_HPP
