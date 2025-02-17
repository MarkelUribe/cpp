#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	*this = copy;
	std::cout << "WrongCat copy constructor called" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat &other) {
	WrongAnimal::operator=(other);
	type = other.type;
	std::cout << "WrongCat copy assigment operator called" << std::endl;
	return (*this);
}
WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
};

void	WrongCat::makeSound() const {
	std::cout << "Im not a cat aaaaa!" << std::endl;
}