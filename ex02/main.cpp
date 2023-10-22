#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

void	i_wanna_go_home(void) {
	system("leaks $PPID");
}

int	main(void) {
	Bureaucrat bru("foo", 1);
	std::cout << bru << std::endl;
	std::cout << std::endl;
	ShrubberyCreationForm test0("syururup");
	PresidentialPardonForm test1("president");
	RobotomyRequestForm test2("robot");
	std::cout << test0 << std::endl;
	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;
	std::cout << std::endl;
	test0.beSigned(bru);
	test1.beSigned(bru);
	test2.beSigned(bru);
	std::cout << std::endl;
	std::cout << test0 << std::endl;
	std::cout << test1 << std::endl;
	std::cout << test2 << std::endl;
	std::cout << std::endl;
	bru.executeForm(test0);
	bru.executeForm(test1);
	bru.executeForm(test2);
	return 0;
}
