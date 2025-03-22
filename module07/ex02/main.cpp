#include "Array.hpp"

int	main(void) {
	Array<std::string> array(2);
	array[0] = "eunoon";
	array[1] = "zeeee";	
	try {
		std::cout << array[0] << std::endl;
		std::cout << array[1] << std::endl;
		array[2] = "mouzz";
		std::cout << array[2] << std::endl;
	}
	catch	(std::out_of_range	&e) {
		std ::cout << e.what() << std::endl;
	}

}