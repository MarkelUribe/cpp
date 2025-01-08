#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie pedro = Zombie(name);
	pedro.announce();
}
