#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name ) {
	Zombie*	horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return horde;
}


/* 	Zombie*	horde = new Zombie[N];

	for (int i=0; i < N; i++)
	{
		std::string	nameN = name;
		nameN += (i + '0');
		horde[i].setName(nameN);
	}

	return horde; */