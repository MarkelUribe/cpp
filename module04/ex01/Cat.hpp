#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain*	brain;

public:
	Cat();
	Cat(const Cat &copy);
	Cat &operator= (const Cat &other);
	~Cat();

	void	makeSound() const;
};

#endif