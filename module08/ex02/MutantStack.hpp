#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack();
	MutantStack(unsigned int n);
	MutantStack(const MutantStack &copy);
	MutantStack &operator= (const MutantStack &model);
	~MutantStack();

	void			addNumber(int nbr);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	
};

#endif