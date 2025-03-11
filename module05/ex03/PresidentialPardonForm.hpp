#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <stdexcept>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator= (const PresidentialPardonForm &other);
	virtual ~PresidentialPardonForm();

	std::string		getTarget(void) const;

	void	execute(Bureaucrat const & executor) const;
};

std::ostream	&operator<<(std::ostream &stream, const AForm &model);

#endif