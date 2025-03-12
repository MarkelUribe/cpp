#include "Form.hpp"
#include "Bureaucrat.hpp"

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

Form::Form(const Form &copy)
	: name(copy.name), isSigned(false),
	signGrade(copy.signGrade),
	executeGrade(copy.executeGrade) {}

Form& Form::operator=(const Form &other) {
	isSigned = other.isSigned;
	return (*this);
}

Form::~Form() {}

std::string	Form::getName(void) const {
	return name;
}
bool	Form::getSigned(void) const {
	return isSigned;
}
int	Form::getSignGrade(void) const {
	return signGrade;
}
int	Form::getExecuteGrade(void) const {
	return executeGrade;
}

std::ostream	&operator<<(std::ostream &stream, const Form &model) {
	if (model.getSigned())
		stream << "Form: " << model.getName() << " is signed ";
	else
		stream << "Form: " << model.getName() << " is NOT signed ";
	stream << "(Needed grade " << model.getSignGrade() << " for signing and ";
	stream << "grade " << model.getExecuteGrade() << " for it to be executed)";
	return (stream);
}

void	Form::beSigned(const Bureaucrat &bureaucrat) {
	std::cout << bureaucrat.getGrade() << this->signGrade << std::endl;
	if (bureaucrat.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}
