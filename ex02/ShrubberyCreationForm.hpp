#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(const ShrubberyCreationForm& object);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(const std::string& target);
		const std::string& getTarget() const;
		void execute(const Bureaucrat& executor) const;

	private:
		const std::string target;

		ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& object);
};

#endif  // SHRUBBERYCREATIONFORM_HPP
