#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy){
	for (size_t i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}
Brain& Brain::operator=(const Brain &other) {
	for (size_t i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	std::cout << "Cat copy assigment operator called" << std::endl;
	return (*this);
}
Brain::~Brain(void) {
	std::cout << "Brain destructor called" << std::endl;
};
