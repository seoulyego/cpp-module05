#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <iostream>

void	i_wanna_go_home(void) {
	system("leaks $PPID");
}

int	main(void) {
	Bureaucrat bru("foo", 1);
    ShrubberyCreationForm test0("srurup");
    PresidentialPardonForm test1("president");
    RobotomyRequestForm test2("robot");
    std::cout << test0.getSignGrade() << std::endl;
    test0.beSigned(bru);
    test1.beSigned(bru);
    test2.beSigned(bru);
    bru.executeForm(test0);
    bru.executeForm(test1);
    bru.executeForm(test2);
	return 0;
}
