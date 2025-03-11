#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <stdexcept>

#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &model);
	Intern	&operator=(const Intern &model);
	~Intern();

	AForm*	makeForm(std::string form, std::string target);
};

#endif