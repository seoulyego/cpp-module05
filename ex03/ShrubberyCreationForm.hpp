#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& object);
		~ShrubberyCreationForm();

		void	execute(const Bureaucrat& executor) const;

	private:
		ShrubberyCreationForm();
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& object);
};

#endif  // SHRUBBERYCREATIONFORM_HPP
