#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try {
		Intern Luis;
		AForm *shrubbery;
		AForm *robotomy;
		AForm *presidential;
		Bureaucrat Manuel("Bureaucrat", 150);

		shrubbery = Luis.makeForm("shrubbery", "Home");
		robotomy = Luis.makeForm("robotomy", "Bender");

		presidential = Luis.makeForm("tax evasion", "someone");
		presidential = Luis.makeForm("presidential", "someone");

		Manuel.signForm(*shrubbery);
		Manuel.signForm(*robotomy);
		Manuel.signForm(*presidential);
		Manuel.executeForm(*shrubbery);
		Manuel.executeForm(*robotomy);
		Manuel.executeForm(*presidential);

		delete shrubbery;
		delete robotomy;
		delete presidential;
	}
	catch (std::exception &_exception) {
		std::cout << _exception.what() << std::endl;
	}
	return (0);
}