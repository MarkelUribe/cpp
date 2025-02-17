#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : AAnimal(copy) {
	*this = copy;
	brain = new Brain(*copy.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}
Cat& Cat::operator=(const Cat &other) {
	AAnimal::operator=(other);
	type = other.type;
	brain = new Brain(*other.brain);
	std::cout << "Cat copy assigment operator called" << std::endl;
	return (*this);
}
Cat::~Cat(void) {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
};

void	Cat::makeSound() const {
	std::cout << "Miau!" << std::endl;
}