#ifndef FORM_HPP
# define FORM_HPP

# include <string>

class Bureaucrat;

class Form {
	public:
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		Form(const std::string& name, const int sign_grade, const int exec_grade);
		Form(const Form& object);
		~Form();

		const std::string&	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				setSigned(bool is_signed);
		void				beSigned(const Bureaucrat& b);

		private:
			const std::string	name;
			bool				is_signed;
			const int			sign_grade;
			const int			exec_grade;

			Form();
			Form&	operator=(const Form& object);
};

std::ostream&	operator<<(std::ostream& os, const Form& f);

#endif  // FORM_HPP
