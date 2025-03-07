#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5) {
	target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
: AForm("PresidentialPardonForm", 25, 5)
{
	this->target = copy.target;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other)
		this->target = other.target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string	PresidentialPardonForm::getTarget() const {
	return(target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned())
	{
		throw NotSignedException();
	}
	if (this->getExecuteGrade() > executor.getGrade())
	{
		throw GradeTooLowException();
	}
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}