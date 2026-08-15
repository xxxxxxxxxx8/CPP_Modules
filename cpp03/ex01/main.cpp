
#include <ScavTrap.hpp>

int main()
{
	ScavTrap var("Amigo");
	ClapTrap *ptr = &var;

	ptr->attack("Clap");

}
