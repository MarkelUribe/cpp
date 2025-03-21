#include "Array.hpp"

template <typename T>
Array<T>::Array(): _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n): _array(new t[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other): _array(NULL), _size(0) {*this = other;}

template <typename T>
Array<T>::~Array() {delete[] _array;}

template <typename T>
unsigned int	Array<T>::size() const {return (_size);}