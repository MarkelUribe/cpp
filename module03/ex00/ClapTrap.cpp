#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoint(10), _attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoint = other._energyPoint;
	_attackDamage = other._attackDamage;
	std::cout << "Copy assigment operator called" << std::endl;
	return (*this);
}
ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called" << std::endl;
};

void ClapTrap::attack(const std::string& target) {
	if (_energyPoint <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points! "  << std::endl;
		return ;
	}
	_energyPoint--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " \
	<< _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= (unsigned int)_hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " took " << amount << \
	" points of damage! now its health is " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoint <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points! "  << std::endl;
		return ;
	}
	_energyPoint--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repaired itself by " << amount \
	<< " points! now its health is " << _hitPoints << std::endl;
}