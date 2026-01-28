#include <iostream>
#include <typeinfo>

template <typename T>
void iter(T* array, size_t length, void (*function)(T&)) {
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void iter(const T* array, size_t length, void (*function)(const T&)) {
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void	printvalue(T val) {
	std::cout << val << std::endl;
}