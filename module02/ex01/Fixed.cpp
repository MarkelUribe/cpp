#include "Fixed.hpp"

Fixed::Fixed(void) : _number(0) {
	std::cout << "Default constructor called" << std::endl;
};
Fixed::Fixed(const Fixed &fixed) {
	_number = fixed._number;
	std::cout << "Copy constructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed &fixed) {
	if (this != &fixed)
		_number = fixed._number;
	std::cout << "Copy assigment operator called" << std::endl;
	return *this;
}
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
};
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _number;
}
void Fixed::setRawBits( int const raw ){
	_number = raw;
	std::cout << "setRawBits member function called" << std::endl;
}