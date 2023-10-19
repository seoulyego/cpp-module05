#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <stdbool.h>

class Bureaucrat;

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
		Form(const Form& object);
		Form& operator=(const Form& object);
		~Form();

		Form(const std::string name, const int sign_grade, const int exec_grade);
		const std::string	getName() const;
		bool 				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				setSigned(bool is_signed);
		bool				beSigned(const Bureaucrat& b);
};

std::ostream&	operator<<(std::ostream& os, const Form& f);

#endif  // FORM_HPP
