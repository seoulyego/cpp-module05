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

		AForm(const std::string& name, const int sign_grade, const int exec_grade);
		AForm(const AForm& object);
		virtual ~AForm();

		const std::string&	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				setSigned(bool is_signed);
		void				beSigned(Bureaucrat& b);
		virtual void		execute(const Bureaucrat& executor) const = 0;

		private:
			const std::string	name;
			bool				is_signed;
			const int			sign_grade;
			const int			exec_grade;

			AForm();
			AForm&	operator=(const AForm& object);
};

std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif  // AFORM_HPP
