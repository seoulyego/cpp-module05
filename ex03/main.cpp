#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

void i_wanna_go_home(void) {
	system("leaks $PPID");
}

int main(void) {
	try {
		Bureaucrat bureau = Bureaucrat("foo", 15);
		Intern someRandomIntern;
		{
			AForm *rrf;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			bureau.signForm(*rrf);
			bureau.executeForm(*rrf);
			delete rrf;
		}
		{
			AForm *ppf;
			ppf = someRandomIntern.makeForm("Presidential Pardon", "Van De Ven");
			bureau.signForm(*ppf);
			bureau.executeForm(*ppf);
			delete ppf;
		}
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
