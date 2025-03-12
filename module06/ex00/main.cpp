#include <iostream>
#include "ScalarConverter.hpp"

int	main(int argc, char **argv){
	if (argc != 2)
		std::cout << "Wrong argument" << std::endl;
	ScalarConverter::convert(argv[1]);
	return 0;
}