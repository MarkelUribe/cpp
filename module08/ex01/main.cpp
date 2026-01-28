#include "Span.hpp"

#define N 15

int main(void)
{
	try
	{
		Span	s = Span(N);
		int		n;

		srand(time(NULL));
		for (int i = 0; i < N; i++)
		{
			n = rand() % N;
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