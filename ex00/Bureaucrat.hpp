#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <string>

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat &object);
		Bureaucrat&	operator=(const Bureaucrat& object);
		~Bureaucrat();

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		const std::string	getName(void) const;
		const int			getGrade(void) const;
		void				increaseGrade(void);
		void				decreaseGrade(void);

		Bureaucrat&			operator<<(const Bureaucrat& object);
};

#endif  // BUREAUCRAT_HPP
