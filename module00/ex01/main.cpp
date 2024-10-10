#include "PhoneBook.hpp"
#include "utils.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	line;

	while (line.compare("EXIT") != 0)
	{
		line = get_input("Enter input: ");
		if (!line.compare("ADD"))
			phonebook.add();
		else if (!line.compare("SEARCH"))
			phonebook.search();
		else if(line.compare("EXIT") != 0)
			std::cout << "Not a valid input, (ADD, SEARCH or EXIT)" << std::endl;
	}
}