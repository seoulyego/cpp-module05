#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>

class AForm;

class Bureaucrat {
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& object);
		~Bureaucrat();

		const std::string&	getName() const;
		int					getGrade() const;
		void				increaseGrade();
		void				decreaseGrade();
		void				signForm(AForm& form);
		void				executeForm(const AForm& form);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

	private:
		const std::string	_name;
		int					_grade;

		Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat& object);
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

#endif  // BUREAUCRAT_HPP
