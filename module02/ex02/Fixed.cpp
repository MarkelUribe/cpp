#include "Fixed.hpp"

Fixed::Fixed(void) : _number(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) {
 //std::cout  << "Int constructor called" << std::endl;
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
	//std::cout << "Destructor called" << std::endl;
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

bool	Fixed::operator> (const Fixed &other) {return (_number > other._number);}
bool	Fixed::operator< (const Fixed &other) {return (_number < other._number);}
bool	Fixed::operator>= (const Fixed &other) {return (_number >= other._number);}
bool	Fixed::operator<= (const Fixed &other) {return (_number <= other._number);}
bool	Fixed::operator== (const Fixed &other) {return (_number == other._number);}
bool	Fixed::operator!= (const Fixed &other) {return (_number != other._number);}

Fixed	Fixed::operator+ (const Fixed &other) {
	Fixed result;

	result._number = _number + other._number;
	return (result);
}
Fixed	Fixed::operator- (const Fixed &other) {
	Fixed result;

	result._number = _number - other._number;
	return (result);
}
Fixed	Fixed::operator* (const Fixed &other) {
	Fixed result;

	result._number = (_number * other._number) >> _fraction;
	return (result);
}
Fixed	Fixed::operator/ (const Fixed &other)
{
	Fixed result;

	result._number = (_number << _fraction) / other._number;
	return (result);
}

Fixed Fixed::operator++() {_number++; return(*this);}
Fixed Fixed::operator--() {_number--; return(*this);}
Fixed Fixed::operator++(int) {
	Fixed	tmp(*this);
	_number++;
	return (tmp);
}
Fixed Fixed::operator--(int) {
	Fixed	tmp(*this);
	_number--;
	return (tmp);
}

const Fixed& Fixed::min(Fixed const &one, Fixed const &other) {
	if (one._number < other._number)
		return (one);
	else
		return (other);
}
const Fixed& Fixed::max(Fixed const &one, Fixed const &other) {
	if (one._number > other._number)
		return (one);
	else
		return (other);
}