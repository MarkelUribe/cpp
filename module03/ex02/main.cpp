#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap clap = ClapTrap("Clap");
	ScavTrap scav = ScavTrap("Scav");
	FragTrap frag = FragTrap("Frag");

	clap.attack("Scav");
	scav.takeDamage(0);
	scav.beRepaired(2);
	clap.beRepaired(1);
	scav.attack("Clap");
	clap.takeDamage(20);
	scav.guardGate();
	scav.attack("Frag");
	frag.takeDamage(20);
	frag.beRepaired(5);
	frag.highFivesGuys();
	return 0;
}