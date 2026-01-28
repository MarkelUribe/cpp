#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T*				_array;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		Array &operator= (const Array &model);
		~Array();

		unsigned int	size() const;
		T&				operator [] (unsigned int n);
		const T&		operator [] (unsigned int n) const;
};

#include "Array.tpp"

#endif