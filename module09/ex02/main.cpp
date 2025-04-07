#include "PmergeMe.hpp"

void printListOfLists(const std::list<std::list<int> >& listOfLists) {
    std::list<std::list<int> >::const_iterator outer_it;
    for (outer_it = listOfLists.begin(); outer_it != listOfLists.end(); ++outer_it) {
        std::list<int>::const_iterator inner_it;
        for (inner_it = outer_it->begin(); inner_it != outer_it->end(); ++inner_it) {
            std::cout << *inner_it << ", ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char **argv)
{
	if (argc < 3)
		return (std::cerr << "insert the armguments!" << std::endl, 1);
	PmergeMe merge;
	try
	{
		merge.sort(argc, argv);
	}
	catch (const std::exception &e) {std::cerr << e.what() << '\n';}

	return 0;
}
