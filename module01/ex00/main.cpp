#include "Zombie.hpp"

int main(void) {
	Zombie* pedro = newZombie("pedro");
	pedro->announce();
	randomChump("pepe");
	delete pedro;
	return 0;
}