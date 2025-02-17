#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
	*this = copy;
	std::cout << "Cat copy constructor called" << std::endl;
}
Cat& Cat::operator=(const Cat &other) {
	Animal::operator=(other);
	type = other.type;
	std::cout << "Cat copy assigment operator called" << std::endl;
	return (*this);
}
Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
};

void	Cat::makeSound() const {
	std::cout << "Miau!" << std::endl;
}