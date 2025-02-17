#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	*this = copy;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	type = other.type;

	std::cout << "WrongAnimal copy assigment operator called" << std::endl;
	return (*this);
}
WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal of type " << this->type <<  " Destructor called" << std::endl;
};

std::string	WrongAnimal::getType() const {
	return type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "IM NOT AN ANIMAL AAA" << std::endl;
}