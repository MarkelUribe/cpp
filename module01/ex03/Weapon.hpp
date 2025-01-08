#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon
{
private:
	std::string _type;

public:
	Weapon(void);
	~Weapon(void);
	const std::string getType(void);
	void setType(std::string type);
};

#endif