#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->amount_c = 0;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::add() {
	Contact	contact;
	
	contact.set_contact();
	if (this->amount_c > 7)
		amount_c = 0;
	this->contacts[amount_c] = contact;
	this->amount_c++;
}

void	PhoneBook::search() {

}