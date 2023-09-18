#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void	i_wanna_go_home(void) {
	system("leaks $PPID");
}

int	main(void) {
	try {
		Form test_1_0("test_1_0", 1, 0);	
		Form test_200_150("test_200_150", 200, 150);	
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	Form form_1("form_1", 1, 1);	
	Form form_150("form_150", 150, 150);	

	std::cout << std::endl << "====== form ======" << std::endl;
	std::cout << form_1 << std::endl;
	std::cout << form_150 << std::endl;
	std::cout << "==================" << std::endl;
	std::cout << std::endl;

	Bureaucrat bureau_1("bureau_1", 1);
	Bureaucrat bureau_150("bureau_150", 150);

	std::cout << std::endl << "=== bureaucrat ===" << std::endl;
	std::cout << bureau_1 << std::endl;
	std::cout << bureau_150 << std::endl;
	std::cout << "==================" << std::endl;
	std::cout << std::endl;

	bureau_150.signForm(form_1);
	bureau_150.signForm(form_150);
	bureau_1.signForm(form_1);
	bureau_1.signForm(form_150);

	std::cout << std::endl << "====== form ======" << std::endl;
	std::cout << form_1 << std::endl;
	std::cout << form_150 << std::endl;
	std::cout << "==================" << std::endl;

	return 0;
}
