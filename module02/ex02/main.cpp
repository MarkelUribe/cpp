#include "Fixed.hpp"
void	test0()
{
	std::cout << "\nTest 0" << std::endl;
	Fixed zero;
	std::cout << "hola jonh comanche" << std::endl;
	
}

void	test1()
{
	std::cout << "\nTest 1" << std::endl;
	Fixed numero;
	std::cout << numero.getRawBits() << std::endl;
	numero.setRawBits(42);
	std::cout << numero.getRawBits() << std::endl;
}

void	test2()
{
	std::cout << "\nTest 2" << std::endl;
	Fixed numero;
	std::cout << numero.getRawBits() << std::endl;
	numero.setRawBits(42);
	std::cout << numero.getRawBits() << std::endl;
	Fixed otro(numero);
	std::cout << otro.getRawBits() << std::endl;
	Fixed	zero;
	std::cout << zero.getRawBits() << std::endl;
	numero = zero;
	std::cout << numero.getRawBits() << std::endl;
	std::cout << (zero = otro).getRawBits() << std::endl;
	std::cout << zero.getRawBits() << std::endl;
}

void	test3()
{
	std::cout << "\nTest 3" << std::endl;
	
	Fixed	a(42);
	Fixed	b(+0.1F);
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "a + b is " << a + b << std::endl;
	std::cout << "b - a is " << b - a << std::endl;
	Fixed ft(42);
	Fixed ten(10);
	std::cout << "42 * 10 is " << ft * ten << std::endl;
	std::cout << "42 / 10 is " << ft / ten << std::endl;
	std::cout << "42 / 21 is " << ft / Fixed(21) << std::endl;
	std::cout << "42 / 84 is " << ft / Fixed(84) << std::endl;
	std::cout << "42 * b is " << ft * b << std::endl;
	std::cout << "1--" << --Fixed(1) << std::endl;
}

void	test4()
{
	std::cout << "\nTest 4" << std::endl;

	int i = 257;
	Fixed n(256);

	while (i--)
	{
		std::cout << (int)i << "/256= " << Fixed(i) / n << '\n';
	}
}

void	test5()
{
	std::cout << "\nTest 5" << std::endl;

	int i = 257;
	Fixed n(256);

	while (i /= 2)
	{
		std::cout << (int)i << "/256= " << Fixed(i) / n << '\n';
	}
}

void	test6()
{
	std::cout << "\nTest 6" << std::endl;

	int i = 10;
	Fixed n(10);

	while (i -= 1)
	{
		std::cout << (int)i << "/10= " << Fixed(i) / n << '\n';
	}
}

void	test7()
{
	std::cout << "\nTest 7" << std::endl;

	int i = 256;
	Fixed n(2560);

	while (i--)
	{
		std::cout << (int)i << "/2560= " << Fixed(i) / n << '(' << Fixed(i) / n * 256 << "/256)" << '\n';
	}
}

void	test16()
{
	std::cout << "\nTest 16" << std::endl;

	int i = 257;
	Fixed n(256);

	std::cout << std::hex;
	while (i--)
	{
		std::cout << (int)i << "/" << n << "= " << Fixed(i) / n << '\n';
	}
	std::cout << float(42) << "/" << float(10) << "= " << float(42) / float(10) << '\n';
	std::cout << std::dec;
}

void	subjecttest00()
{
	std::cout << "\nTest subject 00" << std::endl;

	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}

void	subjecttest01()
{
	std::cout << "\nTest subject 01" << std::endl;

	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

void	subjecttest02()
{
	std::cout << "\nTest subject 02" << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}

int main()
{
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test16();
	subjecttest00();
	subjecttest01();
	subjecttest02();
	return 0;
}
