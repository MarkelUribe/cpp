#include "easyfind.hpp"

template <typename T>
bool	easyfind(T& cont, int n) {
	typename T::iterator it;


	//it = std::find(cont.begin(), cont.end(), n);
	for (it = cont.begin(); it != cont.end(); ++it) {
		if (*it == n)
			return true;
	}
	//throw std::out_of_range("Element with key " + std::to_string(n) + " not found.");
	return false;
}
