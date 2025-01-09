#include "Harl.hpp"

Harl::Harl(void) {};
Harl::~Harl(void) {};

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "debug comment\n" << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "info comment\n" << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "warning comment\n" << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "error comment\n" << std::endl;
}

void Harl::complain(std::string level) {
	void (Harl::*ptrFunc[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = -1;
	while (++i < 4)
		if (level == levels[i])
			break ;

	switch (i)
	{
	case 0:
		(this->*ptrFunc[0])();
		/* fallthrough */
	case 1:
		(this->*ptrFunc[1])();
		/* fallthrough */
	case 2:
		(this->*ptrFunc[2])();
		/* fallthrough */
	case 3:
		(this->*ptrFunc[3])();
		break;
	
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}