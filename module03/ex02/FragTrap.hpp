#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &copy);
	FragTrap &operator= (const FragTrap &other);
	~FragTrap();

	void	attack(const std::string& target);
	void	highFivesGuys();
};

#endif