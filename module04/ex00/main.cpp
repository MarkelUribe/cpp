#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* 		meta = new Animal();
	const Animal* 		dog = new Dog();
	const Animal* 		cat = new Cat();
	const WrongAnimal*	wanimal = new WrongAnimal();
	const WrongCat*		wcat = new WrongCat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wanimal->getType() << " " << std::endl;
	std::cout << wcat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();
	wanimal->makeSound();
	wcat->makeSound();

	delete meta;
	delete dog;
	delete cat;
	delete wanimal;
	delete wcat;

	return 0;
}
