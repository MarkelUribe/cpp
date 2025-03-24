#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class Span
{
private:
	std::vector<int>	array;
	unsigned int		n;

public:
	Span();
	Span(unsigned int n);
	Span(const Span &copy);
	Span &operator= (const Span &model);
	~Span();

	void			addNumber(int nbr);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	
};

#endif