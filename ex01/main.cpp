#include "Bureaucrat.hpp"
#include <iostream>

void	i_wanna_go_home(void) {
	system("leaks $PPID");
}

int	main(void) {
	try {
		try {
			Bureaucrat test("test", 200);	
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}

		Bureaucrat a("a", 150);
		Bureaucrat b("b", 1);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;

		// a.decreaseGrade();
		// b.increaseGrade();

		//std::cout << a << std::endl;
		//std::cout << b << std::endl;
		//std::cout << std::endl;

		a.increaseGrade();
		b.decreaseGrade();
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}
