#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { _level = 0; }
PmergeMe::PmergeMe(int level) { this->_level = level; }
PmergeMe::PmergeMe(const PmergeMe &other) : _elements(other._elements), _level(other._level) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	_elements = other._elements;
	_level = other._level;
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
	unsigned int pairSize = (int)pow(2, _level);
	if (pairSize == 0)
		pairSize = 1;

	if (_elements.empty() || _elements.back().size() >= pairSize)
	{
		_elements.push_back(n);
		return;
	}
	if (_elements.back().back() < n.back())
		_elements.back().splice(_elements.back().end(), n);
	else
		_elements.back().splice(_elements.back().begin(), n);

}

void	PmergeMe::addElem(std::vector<int> n)
{
	unsigned int pairSize = (int)pow(2, _level);
	if (pairSize == 0)
		pairSize = 1;

	if (_vec_elements.empty() || _vec_elements.back().size() >= pairSize)
	{
		_vec_elements.push_back(n);
		return;
	}
	if (_vec_elements.back().back() < n.back())
		_vec_elements.back().insert(_vec_elements.back().end(), n.begin(), n.end());
	else
		_vec_elements.back().insert(_vec_elements.back().begin(), n.begin(), n.end());
}

void	PmergeMe::copyValues(PmergeMe &tmp)
{
	// Flatten tmp.elements into a single list
	std::list<int> tmp_flat;
	for (std::list<std::list<int> >::iterator it = tmp._elements.begin(); it != tmp._elements.end(); ++it)
		tmp_flat.splice(tmp_flat.end(), *it); // Move nodes instead of copying

	// Rebuild original structure with new order
	std::list<int>::iterator flat_it = tmp_flat.begin();
	for (std::list<std::list<int> >::iterator outer_it = _elements.begin();
		 outer_it != _elements.end() && flat_it != tmp_flat.end();
		 ++outer_it)
	{
		std::list<int> new_group;
		for (size_t i = 0; i < outer_it->size() && flat_it != tmp_flat.end(); ++i)
			new_group.splice(new_group.end(), tmp_flat, flat_it++);
		outer_it->swap(new_group); // Replace the old group with the new one
	}
}

void	PmergeMe::vec_copyValues(PmergeMe &tmp)
{
	// Flatten tmp.elements into a single list
	std::vector<int> tmp_flat;
	for (std::vector<std::vector<int> >::iterator it = tmp._vec_elements.begin(); it != tmp._vec_elements.end(); ++it)
		tmp_flat.insert(tmp_flat.end(), it->begin(), it->end()); // Move nodes instead of copying

	// Rebuild original structure with new order
	std::vector<int>::iterator flat_it = tmp_flat.begin();
	for (std::vector<std::vector<int> >::iterator outer_it = _vec_elements.begin();
		 outer_it != _vec_elements.end() && flat_it != tmp_flat.end();
		 ++outer_it)
	{
		std::vector<int> new_group;
		for (size_t i = 0; i < outer_it->size() && flat_it != tmp_flat.end(); ++i, ++flat_it)
			new_group.push_back(*flat_it);
		*outer_it = new_group;
	}
}

void	PmergeMe::insertElem(std::list<std::list<int> > &pend, std::list<std::list<int> >::iterator &pend_it)
{
	int key = pend_it->back();

	size_t left = 0;
	size_t right = _elements.size();

	while (left < right)
	{
		size_t mid = (left + right) / 2;

		std::list<std::list<int> >::iterator mid_it = _elements.begin();
		std::advance(mid_it, mid);   // walk to mid (C++98 safe)

		if (key < mid_it->back())
			right = mid;
		else
			left = mid + 1;
	}

	std::list<std::list<int> >::iterator insert_it = _elements.begin();
	std::advance(insert_it, left);

	_elements.insert(insert_it, *pend_it);

	pend.erase(pend_it);
	pend_it = pend.begin();
}

void	PmergeMe::insertElem(std::vector<std::vector<int> > &pend, std::vector<std::vector<int> >::iterator &pend_it)
{
	int key = pend_it->back();

	size_t left = 0;
	size_t right = _vec_elements.size();

	while (left < right)
	{
		size_t mid = (left + right) / 2;

		if (key < _vec_elements[mid].back())
			right = mid;
		else
			left = mid + 1;
	}

	_vec_elements.insert(_vec_elements.begin() + left, *pend_it);

	pend.erase(pend_it);
	pend_it = pend.begin();
}

void PmergeMe::insert()
{
	unsigned int pairSize = (int)pow(2, _level);
	if (pairSize == 0)
		pairSize = 1;
		
	std::list<std::list<int> > pend;
	std::list<std::list<int> >::iterator it = _elements.begin();
	std::advance(it, 2);
	for (int i = 1; it != _elements.end(); i++)
	{
		// Save next before splice, since 'it' will be invalidated
		std::list<std::list<int> >::iterator toMove = it++;
		if (toMove->size() == pairSize && i%2)
			pend.splice(pend.end(), _elements, toMove); // Move list from elements to pend
	}
	size_t besugo_len = sizeof(besugo) / sizeof(unsigned int);
	for (size_t i = 1; i < besugo_len && !pend.empty(); ++i)
	{
		unsigned int count = besugo[i] - besugo[i - 1];

		if (count >= pend.size())
			count = pend.size(); // Clamp to size
		if (count == 0)
			continue;
		std::list<std::list<std::list<int> >::iterator> targets;

		it = pend.begin();
		for (unsigned int j = 0; j < count && it != pend.end(); ++j, ++it)
			targets.push_back(it);
		
		// Now insert in reverse order using only the targets list
		std::list<std::list<std::list<int> >::iterator>::reverse_iterator rit;
		while (!targets.empty())
		{
			rit = targets.rbegin();
			insertElem(pend, *rit);
			targets.pop_back(); // removes from the back safely
		}
	}
}

void PmergeMe::vec_insert()
{
	unsigned int pairSize = (int)pow(2, _level);
	if (pairSize == 0)
		pairSize = 1;

	std::vector<std::vector<int> > pend;
	for (size_t i = 2; i < _vec_elements.size(); )
	{
		if (_vec_elements[i].size() == pairSize && (i % 2 == 1))
		{
			pend.push_back(_vec_elements[i]);
			_vec_elements.erase(_vec_elements.begin() + i);
		}
		else
			++i;
	}
	size_t besugo_len = sizeof(besugo) / sizeof(unsigned int);
	for (size_t i = 1; i < besugo_len && !pend.empty(); ++i)
	{
		unsigned int count = besugo[i] - besugo[i - 1];

		if (count >= pend.size())
			count = pend.size(); // Clamp to size
		if (count == 0)
			continue;

		// Process in reverse order using index (no invalidation)
		for (int j = count - 1; j >= 0; --j)
		{
			std::vector<std::vector<int> >::iterator pend_it = pend.begin() + j;
			insertElem(pend, pend_it);
		}
	}
}

void PmergeMe::merge()
{
	PmergeMe tmp(_level + 1);
	unsigned int pairSize = (int)pow(2, _level);
	std::list<std::list<int> >::iterator it;

	for (it = _elements.begin(); it != _elements.end(); it++)
		if (it->size() == pairSize)
			tmp.addElem(*it);
	if (tmp._elements.size() > 2)
		tmp.merge();
	else if (tmp._elements.size() == 2)
		if (tmp._elements.front().size() == tmp._elements.back().size())
			tmp.merge();
	this->copyValues(tmp);
	this->insert();
}

void PmergeMe::vec_merge()
{
	PmergeMe tmp(_level + 1);
	unsigned int pairSize = (int)pow(2, _level);
	std::vector<std::vector<int> >::iterator it;

	for (it = _vec_elements.begin(); it != _vec_elements.end(); it++)
		if (it->size() == pairSize)
			tmp.addElem(*it);
	if (tmp._vec_elements.size() > 2)
		tmp.vec_merge();
	else if (tmp._vec_elements.size() == 2)
		if (tmp._vec_elements.front().size() == tmp._vec_elements.back().size())
			tmp.vec_merge();

	this->vec_copyValues(tmp);
	this->vec_insert();
	//this->printElemets();
	// tmp.printElemets();
}

void PmergeMe::sort(int argc, char **argv)
{
	std::clock_t start, end;
	for (int i = 1; i < argc; i++)
	{
		if (!isNum(argv[i]))
			throw std::runtime_error("Error: Only insert positive integers!");
		else if (atof(argv[i]) > INT_MAX)
			throw std::runtime_error("Error: Don't insert numbers bigger than INT_MAX!");
		std::list<int> list;
		std::vector<int> vector;
		list.push_back(atoi(argv[i]));
		vector.push_back(atoi(argv[i]));
		this->addElem(list);
		this->addElem(vector);
	}

	std::cout << "Before:\t\t";
	printElemets(_elements);
	//list sort
	start = std::clock();
	this->merge();
	_level = 0;
	end = std::clock();
	double list_duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "After:\t\t";
	printElemets(_elements);
	std::cout << "Time to procress a range of " << _elements.size()
		<< " elements with std::list :\t" << list_duration << " miliseconds" << std::endl;

	//vector sort
	start = std::clock();
	this->vec_merge();
	end = std::clock();
	double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
	std::cout << "Time to procress a range of " << _elements.size() <<
		" elements with std::vector :\t" << duration << " miliseconds" << std::endl;
	printElemets(_vec_elements);
}

void printElemets(std::list<std::list<int> > elements)
{
	if (elements.empty())
	{
		std::cout << "[]" << std::endl;
		return;
	}
	std::list<std::list<int> >::const_iterator outer_it;
	for (outer_it = elements.begin(); outer_it != elements.end(); ++outer_it)
	{
		//std::cout << "[";
		std::list<int>::const_iterator inner_it = outer_it->begin();
		if (inner_it != outer_it->end())
		{
			std::cout << *inner_it;
			++inner_it;
			for (; inner_it != outer_it->end(); ++inner_it)
				std::cout << ", " << *inner_it;
		}
		std::cout << " ";
	}
	std::cout << std::endl;
}

void printElemets(std::vector<std::vector<int> > elements)
{
	if (elements.empty())
	{
		std::cout << "[]" << std::endl;
		return;
	}
	std::vector<std::vector<int> >::const_iterator outer_it;
	for (outer_it = elements.begin(); outer_it != elements.end(); ++outer_it)
	{
		std::vector<int>::const_iterator inner_it = outer_it->begin();
		if (inner_it != outer_it->end())
		{
			std::cout << *inner_it;
			++inner_it;
			for (; inner_it != outer_it->end(); ++inner_it)
				std::cout << ", " << *inner_it;
		}
		std::cout << " ";
	}
	std::cout << std::endl;
}
