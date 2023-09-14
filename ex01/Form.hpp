#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>
# include <stdbool.h>

class Form {
	private:
		const std::string	name;
		bool				is_signed;
		const int			sign_grade;
		const int			exec_grade;

	public:
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		Form();
		Form(const std::string name, bool is_signed, const int sign_grade, const int exec_grade);
		Form(Form& object);
		Form& operator=(const Form& object);
		~Form();

		const std::string	getName() const;
		const int			getSignGrade() const;
		const int			getExecGrade() const;
		void				beSigned(Bureaucrat& b);
};

#endif