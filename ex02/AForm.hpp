#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <string>
# include <stdbool.h>

class AForm {
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
		class NotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};

		AForm();
		AForm(const AForm& object);
		AForm& operator=(const AForm& object);
		virtual ~AForm();

		AForm(const std::string name, const int sign_grade, const int exec_grade);
		const std::string	getName() const;
		bool 				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				setSigned(bool is_signed);
		void				beSigned(Bureaucrat& b);
		virtual void		execute(const Bureaucrat& executor) const = 0;
};

std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif  // AFORM_HPP
