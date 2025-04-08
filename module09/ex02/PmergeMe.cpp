#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { level = 1; }
PmergeMe::PmergeMe(int level) { this->level = level; }
PmergeMe::PmergeMe(const PmergeMe &other) : elements(other.elements), level(other.level) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	elements = other.elements;
	level = other.level;
	return *this;
}
PmergeMe::~PmergeMe() {}

const unsigned int PmergeMe::besugo[] = {3, 5, 11, 21, 43, 85, 171, 341,
										 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};

bool isNum(const std::string &s)
{
	if (s.empty())
		return false;
	for (size_t i = 0; i < s.size(); i++)
		if (!isdigit(s[i]))
			return false;
	return true;
}

void PmergeMe::addElem(std::list<int> n)
{
	unsigned int pairSize = (int)pow(2, level);

	if (elements.empty())
	{
		elements.push_back(n);
		return;
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

void PmergeMe::copyValues(PmergeMe &tmp)
{
	// Flatten tmp.elements into a single list
	std::list<int> tmp_flat;
	for (std::list<std::list<int> >::iterator it = tmp.elements.begin(); it != tmp.elements.end(); ++it)
	tmp_flat.splice(tmp_flat.end(), *it); // Move nodes instead of copying

	// Rebuild original structure with new order
	std::list<int>::iterator flat_it = tmp_flat.begin();
	for (std::list<std::list<int> >::iterator outer_it = elements.begin();
	outer_it != elements.end() && flat_it != tmp_flat.end();
	++outer_it)
	{
		std::list<int> new_group;
		for (size_t i = 0; i < outer_it->size() && flat_it != tmp_flat.end(); ++i)
			new_group.splice(new_group.end(), tmp_flat, flat_it++);
		outer_it->swap(new_group); // Replace the old group with the new one
	}
}

void PmergeMe::insert()
{
	unsigned int pairSize = (int)pow(2, level);
	std::list<std::list<int> > pend;
	std::list<std::list<int> >::iterator it = elements.begin();
	std::advance(it, 2);

	this->printElemets();
	while (it != elements.end())
	{
		// Save next before splice, since 'it' will be invalidated
		std::list<std::list<int> >::iterator toMove = it++;
		if (toMove->size() == pairSize)
		pend.splice(pend.end(), elements, toMove); // Move list from elements to pend
	}
	this->printElemets();

}

void	PmergeMe::merge()
{
	PmergeMe tmp(level + 1);
	unsigned int pairSize = (int)pow(2, level);
	std::list<std::list<int> >::iterator it;

	for (it = elements.begin(); it != elements.end(); it++)
		if (it->size() == pairSize)
			tmp.addElem(*it);
	if (tmp.elements.size() > 2)
		tmp.merge();
	else if (tmp.elements.size() == 2)
		if (tmp.elements.front().size() == tmp.elements.back().size())
			tmp.merge();

	this->copyValues(tmp);
	this->insert();
	//this->printElemets();
	//tmp.printElemets();
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
