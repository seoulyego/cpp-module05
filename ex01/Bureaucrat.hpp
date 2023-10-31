#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Form;

class Bureaucrat {
	public:
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& object);
		~Bureaucrat();

		const std::string&	getName() const;
		int					getGrade() const;
		void				increaseGrade();
		void				decreaseGrade();
		void				signForm(Form& f);

		private:
			const std::string	_name;
			int					_grade;

			Bureaucrat();
			Bureaucrat&	operator=(const Bureaucrat& object);
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

#endif  // BUREAUCRAT_HPP
