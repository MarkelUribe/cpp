#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	*this = copy;
	brain = new Brain(*copy.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}
Dog& Dog::operator=(const Dog &other) {
	Animal::operator=(other);
	type = other.type;
	brain = new Brain(*other.brain);
	std::cout << "Dog copy assigment operator called" << std::endl;
	return (*this);
}
Dog::~Dog(void) {
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
};

void	Dog::makeSound() const{
	std::cout << "Uau!" << std::endl;
}