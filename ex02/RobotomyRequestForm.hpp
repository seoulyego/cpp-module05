#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		const std::string target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(const RobotomyRequestForm& object);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& object);
		~RobotomyRequestForm();

		RobotomyRequestForm(const std::string target);
		const std::string		getTarget() const;
		void					execute(const Bureaucrat& executor) const;
};

#endif  // ROBOTOMYREQUESTFORM_HPP
