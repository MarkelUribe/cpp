#include "easyfind.hpp"

template <typename T>
bool	easyfind(const T& cont, int n) {
	vector<T>::iterator it;

	for (it = cont.begin(); it != cont.end(); ++it) {
		if (*it == n)
			return true;
	}
	//throw std::out_of_range("Element with key " + std::to_string(n) + " not found.");
	return false;
}
