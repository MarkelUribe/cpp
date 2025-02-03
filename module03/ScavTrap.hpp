#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &copy);
	ScavTrap &operator= (const ScavTrap &other);
	~ScavTrap();

	void attack(const std::string& target);
};

#endif