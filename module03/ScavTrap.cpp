#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) {
	*this = copy;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoint = other._energyPoint;
	_attackDamage = other._attackDamage;
	std::cout << "ScavTrap copy assigment operator called" << std::endl;
	return (*this);
}
ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
};

void ClapTrap::attack(const std::string& target) {
	if (_energyPoint <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points! "  << std::endl;
		return ;
	}
	_energyPoint--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " \
	<< _hitPoints << " points of damage!" << std::endl;
}