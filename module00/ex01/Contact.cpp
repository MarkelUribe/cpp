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

std::string	Contact::get_first_name(void){
	return (first_name);
}

std::string	Contact::get_last_name(void){
	return (last_name);
}

std::string	Contact::get_nickname(void){
	return (nickname);
}

std::string	Contact::get_phone(void){
	return (phone);
}

std::string	Contact::get_secret(void){
	return (secret);
}
