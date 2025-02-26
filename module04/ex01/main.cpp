#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int	amount = 6;
	const Animal* bag[amount];

	for (int i = 0; i < amount; i++) {
		if (i < amount / 2)
			bag[i] = new Cat();
		else
			bag[i] = new Dog();
	}

	for (int i = 0; i < amount; i++)
		std::cout << bag[i]->getType() << std::endl;
	
	for (int i = 0; i < amount; i++)
		bag[i]->makeSound();

	for (int i = 0; i < amount; i++)
		delete bag[i];
	Dog	pup;
	Dog	pupCpy(pup);
	return 0;
}
