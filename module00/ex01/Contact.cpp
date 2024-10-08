#include "Contact.hpp"

static std::string	get_input(std::string prompt)
{
	std::string	answer;

	while (1) {
		std::cout << prompt << std::flush;
		std::getline(std::cin, answer);
		if (!std::cin.good() || answer.empty()) {
			if (std::cin.eof()) {
				std::cout << "EOF read error" << std::endl;
				exit(1);
			}
			std::cin.clear();
			std::cout << "Invalid, try again" << std::endl;
		}
		else
			break;
	}
	return answer;
}

Contact::Contact(void)
{
	this->first_name = get_input("first name: ");
	this->last_name = get_input("last name: ");
	this->nickname = get_input("nickname: ");
	this->phone = get_input("phone number: ");
	this->secret = get_input("darkest secret: ");
}
