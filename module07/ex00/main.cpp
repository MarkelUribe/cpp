#include "whatever.hpp"

int main(void)
{
/* 	int i_first = 70;
	int i_second = 48;
	swap(i_first, i_second);

	std::cout << i_first << " vs " << i_second << std::endl;

	char c_first = 'c';
	char c_second = 'z';
	std::cout << min(c_first, c_second) << std::endl;

	std::string str_first = "alo";
	std::string str_second = "jelooo";
	std::cout << max(str_first, str_second) << std::endl;
 */
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	return 0;
}