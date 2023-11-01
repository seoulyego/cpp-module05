#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

/*
void i_wanna_go_home(void) {
	system("leaks $PPID");
}
*/

int main(void) {
	try {
		try {
			Bureaucrat test("test", 200);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
			std::cout << std::endl;
		}

		Bureaucrat a("a", 150);
		Bureaucrat b("b", 1);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;

		try {
			a.decreaseGrade();
			b.increaseGrade();
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
			std::cout << std::endl;
		}

		a.increaseGrade();
		b.decreaseGrade();

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
