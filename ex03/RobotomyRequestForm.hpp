#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& object);
		~RobotomyRequestForm();

		void	execute(const Bureaucrat& executor) const;

	private:
		RobotomyRequestForm();
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& object);
};

#endif  // ROBOTOMYREQUESTFORM_HPP
