#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& object);
		~PresidentialPardonForm();

		void	execute(const Bureaucrat& executor) const;

	private:
		PresidentialPardonForm();
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& object);
};

#endif  // PRESIDENTIALPARDONFORM_HPP
