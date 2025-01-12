#include "Fixed.hpp"

Fixed::Fixed(void) : _number(0) {};
Fixed::Fixed(const Fixed &fixed) {_number = fixed._number;}
Fixed::operator=(const Fixed &fixed) {

}