#include "Weapon.hpp"

Weapon::Weapon(void) {};
Weapon::~Weapon(void) {};

const std::string Weapon::getType(void) {
	return this->_type;
}

void Weapon::setType(std::string type) {
	this->_type = type;
}
