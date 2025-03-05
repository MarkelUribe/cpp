#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int		signGrade;
	const int		executeGrade;

public:
	Form();
	Form(std::string name, int signGrade, int executeGrade);
	Form(const Form &copy);
	Form &operator= (const Form &other);
	~Form();

	std::string	getName(void) const;
	bool		getSigned(void) const;
	int			getSignGrade(void) const;
	int			getExecuteGrade(void) const;

	void		incrementGrade(void);
	void		decrementGrade(void);

	void		beSigned(const Bureaucrat &bureaucrat);

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

std::ostream	&operator<<(std::ostream &_ostream, const Form &model);

#endif