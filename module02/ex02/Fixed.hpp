#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_number;
	static const int	_fraction = 8;

public:
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed &fixed);
	Fixed &operator= (const Fixed &fixed);
	~Fixed();
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator> (const Fixed &other);
	bool	operator< (const Fixed &other);
	bool	operator>= (const Fixed &other);
	bool	operator<= (const Fixed &other);
	bool	operator== (const Fixed &other);
	bool	operator!= (const Fixed &other);

	Fixed	operator+ (const Fixed &other);
	Fixed	operator- (const Fixed &other);
	Fixed	operator* (const Fixed &other);
	Fixed	operator/ (const Fixed &other);

	Fixed operator++(int);
	Fixed operator--(int);
	Fixed operator++();
	Fixed operator--();

	static const Fixed& min(Fixed const &one, Fixed const &other);
	static const Fixed& max(Fixed const &one, Fixed const &other);
};

std::ostream& operator<< (std::ostream &out, const Fixed &c);

#endif