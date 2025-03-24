#include "easyfind.hpp"

int main(void) {
	std::vector<int> vec = std::vector<int>({1, 2, 3});
	//std::vector<int> vec = {1, 2, 3, 4, 5};

	if(easyfind(vec, 25))
		std::cout << "number found!" << std::endl;
	else
		std::cout << "number NOT found!" << std::endl;
}