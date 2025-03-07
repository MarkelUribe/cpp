#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string	target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm &operator= (const RobotomyRequestForm &other);
	virtual ~RobotomyRequestForm();

	std::string		getTarget(void) const;

	void	execute(Bureaucrat const & executor) const;
};

std::ostream	&operator<<(std::ostream &stream, const AForm &model);

#endif