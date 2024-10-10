#include "utils.hpp"

std::string	get_input(std::string prompt)
{
	std::string	answer;

	while (1) {
		if (prompt.compare("") != 0)
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
