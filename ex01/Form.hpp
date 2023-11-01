#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>
# include <exception>

class Form {
	public:
		Form(const std::string& name, const int sign_grade, const int exec_grade);
		Form(const Form& object);
		~Form();

		const std::string&	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				beSigned(const Bureaucrat& b);

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
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

		Form();
		Form&	operator=(const Form& object);
};

std::ostream&	operator<<(std::ostream& os, const Form& f);

#endif  // FORM_HPP
