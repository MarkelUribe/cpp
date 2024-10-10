#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void	add();
	void	search();

private:
	Contact	contacts[8];
	int		amount_c;
};

#endif