#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
	*this = copy;
	std::cout << "FragTrap copy constructor called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap &other) {
	ClapTrap::operator=(other);
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoint = other._energyPoint;
		_attackDamage = other._attackDamage;
		std::cout << "FragTrap copy assigment operator called" << std::endl;
	}
	return (*this);
}
FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << this->_name << " Destructor called" << std::endl;
};

void FragTrap::attack(const std::string& target) {
	if (_energyPoint <= 0)
	{
		std::cout << "FragTrap " << _name << " has no energy points! "  << std::endl;
		return ;
	}
	_energyPoint--;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " \
	<< _hitPoints << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " wants a high five!" << std::endl;
}
