#include "AAnimal.hpp"

AAnimal::AAnimal() : type("") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) {
	*this = copy;
	std::cout << "AAnimal copy constructor called" << std::endl;
}
AAnimal& AAnimal::operator=(const AAnimal &other) {
	type = other.type;

	std::cout << "Animal copy assigment operator called" << std::endl;
	return (*this);
}
AAnimal::~AAnimal(void) {
	std::cout << "AAnimal of type " << this->type <<  " Destructor called" << std::endl;
};

std::string	AAnimal::getType() const {
	return type;
}
