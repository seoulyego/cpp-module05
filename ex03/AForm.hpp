#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <string>

class AForm {
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

		AForm(const std::string& name, const std::string& target, const int sign_grade, const int exec_grade);
		AForm(const AForm& object);
		virtual ~AForm();

		const std::string&	getName() const;
		const std::string&	getTarget() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				beSigned(Bureaucrat& b);
		virtual void		execute(const Bureaucrat& executor) const = 0;

		private:
			const std::string	_name;
			const std::string	_target;
			bool				_isSigned;
			const int			_signGrade;
			const int			_execGrade;

			AForm();
			AForm&	operator=(const AForm& object);
};

std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif  // AFORM_HPP
