#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->amount_c = 0;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::add() {
	Contact	contact;
	
	contact.set_contact();
	if (this->amount_c > 8)
		amount_c = 0;
	this->contacts[amount_c] = contact;
	this->amount_c++;
}

void	print_col(std::string str)
{
	if (str.length() > 10)
		std::cout << "|" << str.substr(0, 9) << ".";
	else 
		std::cout << "|" << std::setw(10) << std::right << str;
}

void	PhoneBook::search() {
	std::string	prompt;

	if (amount_c == 0)
	{
		std::cout << "There are no accounts created!" << std::endl;
		return ;
	}
	std::cout << "|INDEX     |FIRST_NAME|SECOND_NA.|NICK_NAME |" << std::endl;
	std::cout << "=============================================" << std::endl;
	for (int i = 0; i < amount_c; i++)
	{
		std::string number(1, i + '0');
		print_col(number);
		print_col(contacts[i].get_first_name());
		print_col(contacts[i].get_last_name());
		print_col(contacts[i].get_nickname());
		std::cout << "|" << std::endl;
	}
	std::cout << "=============================================" << std::endl;
	std::cout << "What Contact do you want to see?" << std::endl;
	std::cout << "PLEASE INSERT THE INDEX:" << std::endl;
	while (true)
	{
		std::getline(std::cin, prompt);
		for (int i = 0; i < amount_c; i++)
		{
			if (prompt.length() == 1 && prompt[0] - '0' == i)
			{
				std::cout << "FIRST NAME: " << contacts[i].get_first_name() << std::endl;
				std::cout << "SECOND NAME: " << contacts[i].get_last_name() << std::endl;
				std::cout << "NICK NAME: " << contacts[i].get_nickname() << std::endl;
				std::cout << "PHONE NUMBER: " << contacts[i].get_phone() << std::endl;
				std::cout << "DARK SECRET: " << contacts[i].get_secret() << std::endl;
				return ;
			}
		}
		std::cout << "Please insert a valid index!" << std::endl;
	}
}