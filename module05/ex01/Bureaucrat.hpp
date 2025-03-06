#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	name;
	unsigned int		grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator= (const Bureaucrat &other);
	~Bureaucrat();

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

	std::string		getName(void) const;
	unsigned int	getGrade(void) const;

	void		incrementGrade(void);
	void		decrementGrade(void);

	void		signForm(Form &form) const;
};

std::ostream	&operator<<(std::ostream &_ostream, const Bureaucrat &_bureaucrat);

#endif