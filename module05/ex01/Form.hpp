#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const unsigned int			signGrade;
	const unsigned int			executeGrade;

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

	void		beSigned(const Bureaucrat &bureaucrat);

	class	GradeTooHighException: public std::exception {
		public:
			const char *what() const throw();
	};
	class	GradeTooLowException: public std::exception {
		public:
			const char *what() const throw();
	};

};

std::ostream	&operator<<(std::ostream &stream, const Form &model);

#endif