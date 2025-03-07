#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <stdexcept>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string	target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator= (const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();

	std::string		getTarget(void) const;

	void	execute(Bureaucrat const & executor) const;
};

std::ostream	&operator<<(std::ostream &stream, const AForm &model);

#endif