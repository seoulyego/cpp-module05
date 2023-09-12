#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <string>

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
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat& object);
		Bureaucrat&	operator=(const Bureaucrat& object);
		~Bureaucrat();

		const std::string	getName(void) const;
		const int			getGrade(void) const;
		void				increaseGrade(void);
		void				decreaseGrade(void);
};

	std::ostream&	operator<<(std::ostream& os, const Bureaucrat& object);

#endif  // BUREAUCRAT_HPP
