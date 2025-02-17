#include "Animal.hpp"

Animal::Animal() : type("") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy) {
	*this = copy;
	std::cout << "Animal copy constructor called" << std::endl;
}
Animal& Animal::operator=(const Animal &other) {
	type = other.type;

	std::cout << "Animal copy assigment operator called" << std::endl;
	return (*this);
}
Animal::~Animal(void) {
	std::cout << "Animal of type " << this->type <<  " Destructor called" << std::endl;
};

std::string	Animal::getType() const {
	return type;
}

void	Animal::makeSound() const {
	std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAA" << std::endl;
}