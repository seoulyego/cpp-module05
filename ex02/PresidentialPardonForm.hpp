#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		const std::string	target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(const PresidentialPardonForm& object);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& object);
		~PresidentialPardonForm();

		PresidentialPardonForm(const std::string target);
		const std::string		getTarget() const;
		void					execute(const Bureaucrat& executor) const;
};

#endif  // PRESIDENTIALPARDONFORM_HPP
