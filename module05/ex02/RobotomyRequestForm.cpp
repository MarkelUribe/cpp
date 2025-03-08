#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45) {
	target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
: AForm("RobotomyRequestForm", 72, 45)
{
	this->target = copy.target;
}

RobotomyRequestForm   &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other)
		this->target = other.target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string	RobotomyRequestForm::getTarget() const {
	return(target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned())
	{
		throw NotSignedException();
	}
	if (this->getExecuteGrade() < executor.getGrade())
	{
		throw GradeTooLowException();
	}
	std::cout << "Making some drilling noises...\n";
	srand(time(0));
	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully!\n";
	else
		std::cout << "Robotomy failed for " << target << "\n";
}