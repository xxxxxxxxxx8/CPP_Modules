
#include <ScavTrap.hpp>
#include <FragTrap.hpp>

int main()
{

	FragTrap Frag("dahmane");
	FragTrap Frag2;
	ScavTrap Scav;

	Scav.attack("Legend");
	Frag2 = Frag;
	Frag2.attack("wa7ashetini");
}
