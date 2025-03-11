#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <iostream>
#include <fstream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool				isSigned;
	const unsigned int			signGrade;
	const unsigned int			executeGrade;

public:
	AForm();
	AForm(std::string name, int signGrade, int executeGrade);
	AForm(const AForm &copy);
	AForm &operator= (const AForm &other);
	virtual 
	~AForm();

	std::string		getName(void) const;
	bool			getSigned(void) const;
	unsigned int	getSignGrade(void) const;
	unsigned int	getExecuteGrade(void) const;

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
	class NotSignedException : public std::exception {
		public:
			const char *what() const throw() {
				return ("Form not signed");
			}
	};
};

std::ostream	&operator<<(std::ostream &stream, const AForm &model);

#endif