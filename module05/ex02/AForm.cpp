#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("AForm"), signGrade(150), executeGrade(1)
{
	isSigned = false;
}

AForm::AForm(std::string name, int sign_grade, int execute_grade)
	: name(name), signGrade(sign_grade), executeGrade(execute_grade)
{
	if (sign_grade < 1)
		throw AForm::GradeTooLowException();
	if (sign_grade > 150)
		throw AForm::GradeTooHighException();
	if (execute_grade < 1)
		throw AForm::GradeTooLowException();
	if (execute_grade > 150)
		throw AForm::GradeTooHighException();
	isSigned = false;
}

AForm::AForm(const AForm &copy)
	: name(copy.name), isSigned(false),
	signGrade(copy.signGrade),
	executeGrade(copy.executeGrade) {}

AForm& AForm::operator=(const AForm &other) {
	isSigned = other.isSigned;
	return (*this);
}

AForm::~AForm() {}

std::string	AForm::getName(void) const {
	return name;
}
bool	AForm::getSigned(void) const {
	return isSigned;
}
unsigned int	AForm::getSignGrade(void) const {
	return signGrade;
}
unsigned int	AForm::getExecuteGrade(void) const {
	return executeGrade;
}

std::ostream	&operator<<(std::ostream &stream, const AForm &model) {
	if (model.getSigned())
		stream << "Form: " << model.getName() << " is signed ";
	else
		stream << "Form: " << model.getName() << " is NOT signed ";
	stream << "(Needed grade " << model.getSignGrade() << " for signing and ";
	stream << "grade " << model.getExecuteGrade() << " for it to be executed)";
	return (stream);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat) {
	std::cout << bureaucrat.getGrade() << this->signGrade << std::endl;
	if (bureaucrat.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

void	AForm::checkExec(Bureaucrat const & executor) const {
	if (!this->getSigned())
			throw NotSignedException();
		if (this->getExecuteGrade() < executor.getGrade())
			throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const char* AForm::NotSignedException::what() const throw() {
	return "Form not signed";
}