#include "Contact.hpp"
#include "utils.hpp"

Contact::Contact(void) {}

void	Contact::set_contact(void) {
	this->first_name = get_input("first name: ");
	this->last_name = get_input("last name: ");
	this->nickname = get_input("nickname: ");
	this->phone = get_input("phone number: ");
	this->secret = get_input("darkest secret: ");
}

Contact::~Contact(void){}
