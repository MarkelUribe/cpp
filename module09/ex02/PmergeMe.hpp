#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <list>
#include <cmath>

class PmergeMe
{
private:
	std::list<std::list<int> > elements;
	int	level;

public:
	PmergeMe();
	PmergeMe(int level);
	PmergeMe(const PmergeMe& other);
	PmergeMe&	operator = (const PmergeMe& other);
	~PmergeMe();

	void	addElem(std::list<int> n);
	void	sort(int argc, char **argv);
	void	merge();
	void	printElemets();
};

#endif