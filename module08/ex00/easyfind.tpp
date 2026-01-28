#include "easyfind.hpp"

template <typename T>
bool	easyfind(T& cont, int n)
{
	if (std::find(cont.begin(), cont.end(), n) != cont.end())
		return true;
	return false;
}
