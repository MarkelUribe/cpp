#include "Span.hpp"

int main(void)
{
	try
	{
		Span	s = Span(10000);
		int		n;

		srand(time(NULL));
		for (int i = 0; i < 10000; i++)
		{
			n = rand() % 100000;
			std::cout << n << ", ";
			s.addNumber(n);
		}
		
		std::cout << std::endl;

		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span: " << s.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}