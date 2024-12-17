#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>

class Contact {

private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone;
	std::string	secret;

public:
	Contact(void);
	~Contact(void);
	void		set_contact(void);
	std::string	get_first_name(void);
	std::string	get_last_name(void);
	std::string	get_nickname(void);
	std::string	get_phone(void);
	std::string	get_secret(void);
};

#endif