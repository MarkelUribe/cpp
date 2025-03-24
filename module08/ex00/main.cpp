#include "easyfind.hpp"

int main(void) {
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(10);
	vec.push_back(25);
	vec.push_back(33);
	if(easyfind(vec, 25))
		std::cout << "number found!" << std::endl;
	else
		std::cout << "number NOT found!" << std::endl;
}