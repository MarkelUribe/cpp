#include "Zombie.hpp"

int main(void) {
	int n = 15;
	Zombie* horde = zombieHorde(n, "xabi");
	
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;
}