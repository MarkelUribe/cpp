#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie* pedro = new Zombie(name);
	return pedro;
}