#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <list>
#include <cmath>

#define BESUGO 

class PmergeMe
{
private:
	std::list<std::list<int> > elements;
	int	level;
	static const unsigned int besugo[];

public:
	PmergeMe();
	PmergeMe(int level);
	PmergeMe(const PmergeMe& other);
	PmergeMe&	operator = (const PmergeMe& other);
	~PmergeMe();

	void		addElem(std::list<int> n);
	void		sort(int argc, char **argv);
	void		merge();
	void		insert();
	void		copyValues(PmergeMe &tmp);
	void		printElemets();
};

#endif