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

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
	*this = copy;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	ClapTrap::operator=(other);
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoint = other._energyPoint;
		_attackDamage = other._attackDamage;
		std::cout << "ScavTrap copy assigment operator called" << std::endl;
	}
	return (*this);
}
ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->_name << " Destructor called" << std::endl;
};

void ScavTrap::attack(const std::string& target) {
	if (_energyPoint <= 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy points! "  << std::endl;
		return ;
	}
	_energyPoint--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " \
	<< _attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}
