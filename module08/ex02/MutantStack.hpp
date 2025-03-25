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

	typedef typename std::deque<T>::iterator	iterator;
	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"

#endif