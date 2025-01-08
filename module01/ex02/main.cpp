#include <string>
#include <iostream>

int main(void) {
	std::string		A = "HI THIS IS BRAIN";
	std::string*	stringPTR = &A;
	std::string		stringREF = A;

	std::cout << "variable address: " << &A << std::endl;
	std::cout << "pointer address: " << stringPTR << std::endl;
	std::cout << "reference address: " << &stringREF << std::endl;

	std::cout << "\nvariable value: " << A << std::endl;
	std::cout << "pointer value: " << *stringPTR << std::endl;
	std::cout << "reference value: " << stringREF << std::endl;

	return 0;
}