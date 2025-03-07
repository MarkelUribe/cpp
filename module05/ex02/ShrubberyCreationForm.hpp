#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <stdexcept>

#include "AForm.hpp"

class ShrubberyCreationForm : AForm
{
private:
	const std::string	target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator= (const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();

	std::string	getTarget(void) const;

	void		beSigned(const Bureaucrat &bureaucrat);

	virtual void	execute(Bureaucrat const & executor) const = 0;

	class	GradeTooHighException: public std::exception {
		public:
			const char *what() const throw() {
				return "Grade too high";
			}
	};
	class	GradeTooLowException: public std::exception {
		public:
			const char *what() const throw() {
				return "Grade too low";
			}
	};

};

std::ostream	&operator<<(std::ostream &stream, const AForm &model);

#endif