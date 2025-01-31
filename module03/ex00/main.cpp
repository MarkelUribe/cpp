#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap clap = ClapTrap("clap");
	ClapTrap trap = ClapTrap("trap");

	clap.attack("trap");
	trap.takeDamage(10);
	trap.beRepaired(2);
	return 0;
}