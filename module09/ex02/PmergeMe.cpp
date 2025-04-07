#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { level = 0; }
PmergeMe::PmergeMe(int level) { this->level = level; }
PmergeMe::PmergeMe(const PmergeMe &other) : elements(other.elements), level(other.level) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	elements = other.elements;
	level = other.level;
	return *this;
}
PmergeMe::~PmergeMe() {}

void PmergeMe::addElem(std::list<int> n)
{
	unsigned int pairSize = (int)pow(2, level);

	if (elements.empty())
	{
		elements.push_back(n);
		return ;
	}
	if (elements.back().size() < pairSize)
	{
		if (elements.back().back() < n.back())
			elements.back().splice(elements.back().end(), n);
		else
			elements.back().splice(elements.back().begin(), n);
		return;
	}
	elements.push_back(n);
}

bool isNum(const std::string &s)
{
	if (s.empty())
		return false;
	for (size_t i = 0; i < s.size(); i++)
		if (!isdigit(s[i]))
			return false;
	return true;
}

void PmergeMe::merge()
{
	PmergeMe tmp(level++);
	unsigned int pairSize = (int)pow(2, level);
	std::list<std::list<int> >::iterator it;
	for (it = elements.begin(); it != elements.end(); it++)
		if (it->size() == pairSize)
			tmp.addElem(std::list<int>(*it));
	if (tmp.elements.size() > 2)
		tmp.merge();
	else if (tmp.elements.size() == 2)
		if (tmp.elements.front().size() == tmp.elements.back().size())
			tmp.merge();
	//this->printElemets();
}

void PmergeMe::sort(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (!isNum(argv[i]))
			throw std::runtime_error("Only insert positive integers!");
		std::list<int> list;
		list.push_back(atoi(argv[i]));
		this->addElem(list);
	}
	this->printElemets();
	this->merge();
}

void PmergeMe::printElemets()
{
	if (elements.empty())
	{
		std::cout << "[]" << std::endl;
		return;
	}
	std::list<std::list<int> >::const_iterator outer_it;
	for (outer_it = elements.begin(); outer_it != elements.end(); ++outer_it)
	{
		std::cout << "[";
		std::list<int>::const_iterator inner_it = outer_it->begin();
		if (inner_it != outer_it->end())
		{
			std::cout << *inner_it;
			++inner_it;
			for (; inner_it != outer_it->end(); ++inner_it)
				std::cout << ", " << *inner_it;
		}
		std::cout << "] ";
	}
	std::cout << std::endl;
}
