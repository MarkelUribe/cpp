#include "Harl.hpp"

Harl::Harl(void) {};
Harl::~Harl(void) {};

void Harl::debug(void) {
	std::cout << "debug comment" << std::endl;
}

void Harl::info(void) {
	std::cout << "info comment" << std::endl;
}

void Harl::warning(void) {
	std::cout << "warning comment" << std::endl;
}

void Harl::error(void) {
	std::cout << "error comment" << std::endl;
}

void Harl::complain(std::string level) {
	void (Harl::*ptrFunc[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i=0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*ptrFunc[i])();
			break ;
		}
	}
}