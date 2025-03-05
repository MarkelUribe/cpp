#include "Form.hpp"

Form::Form(): name("Form"), signGrade(150), executeGrade(1)
{
	isSigned = false;
}

Form::Form(std::string name, int sign_grade, int execute_grade)
	: name(name), signGrade(sign_grade), executeGrade(execute_grade)
{
	if (sign_grade < 1)
		throw Form::GradeTooLowException();
	if (sign_grade > 150)
		throw Form::GradeTooHighException();
	if (execute_grade < 1)
		throw Form::GradeTooLowException();
	if (execute_grade > 150)
		throw Form::GradeTooHighException();
	isSigned = false;
}