#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
private:
	int 				_number;
	static const int	_fraction;

public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed operator = (const Fixed &fixed);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif