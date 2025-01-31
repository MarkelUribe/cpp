#include "Fixed.hpp"

Fixed::Fixed(void) : _number(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) {
std::cout  << "Int constructor called" << std::endl;
	_number = number << _fraction;
}

Fixed::Fixed(const float number) {
	std::cout  << "Float constructor called" << std::endl;
	_number = (int)roundf(number * (1 << _fraction));
}
Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
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

float	Fixed::toFloat(void) const {
	return ((float)_number / (1 << _fraction));
};

int		Fixed::toInt(void) const {
	return ((int)(_number  / (1 << _fraction)));
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	return (os <<(fixed.toFloat()));
}