#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	*this = copy;
	std::cout << "Dog copy constructor called" << std::endl;
}
Dog& Dog::operator=(const Dog &other) {
	Animal::operator=(other);
	type = other.type;
	std::cout << "Dog copy assigment operator called" << std::endl;
	return (*this);
}
Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
};

void	Dog::makeSound() const{
	std::cout << "Uau!" << std::endl;
}