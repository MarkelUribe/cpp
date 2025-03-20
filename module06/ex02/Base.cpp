#include "Base.hpp"

Base::~Base() {}

Base*	generate(void) {
	std::srand(std::time(0));
	
	char n = std::rand() % 3;
	if (n == 0)
		return (new A());
	if (n == 1)
		return (new B());
	if (n == 2)
		return (new C());
	return NULL;
}

void	identify(Base* p) {
	std::cout << "Pointer: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p) {
	std::cout << "Reference: ";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e) {}
}