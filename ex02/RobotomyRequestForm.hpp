#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& object);
		~RobotomyRequestForm();

		const std::string&	getTarget() const;
		void				execute(const Bureaucrat& executor) const;

	private:
		const std::string target;

		RobotomyRequestForm();
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& object);
};

#endif  // ROBOTOMYREQUESTFORM_HPP
