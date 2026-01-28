#include "Span.hpp"

#define N 10

int main(void)
{
	try
	{
		Span				s = Span(N);
		std::vector<int>	v;
		int					n;

		srand(time(NULL));
		for (int i = 0; i < N; i++)
		{
			n = rand() % N;
			std::cout << n << ", ";
			v.push_back(n);
		}

		s.addNumber(v.begin(), v.end());

		std::cout << "\nshortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span: " << s.longestSpan() << std::endl;
		
		std::cout << std::endl;

		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span: " << s.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}