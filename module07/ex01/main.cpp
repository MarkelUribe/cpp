#include "iter.hpp"

int	main(void) {
	int intArray[] = {1, 2, 3, 99, 48};
	const char charArray[] = {'a', 'B', '8', 'd', 'e', '-', 21};
	
	std::cout << "int array:" << std::endl;
	iter(intArray, 5, printvalue);
	std::cout << "char array:" << std::endl;
	iter(charArray, 7, printvalue);
}