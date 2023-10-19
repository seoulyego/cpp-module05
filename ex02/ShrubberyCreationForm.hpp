#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		const std::string target;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(const ShrubberyCreationForm& object);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& object);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(const std::string target);
		const std::string		getTarget() const;
		void					execute(const Bureaucrat& executor) const;
};

#endif  // SHRUBBERYCREATIONFORM_HPP
