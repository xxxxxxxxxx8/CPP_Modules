
#include <Zombie.hpp>

Zombie* newZombie( std::string name )
{
	Zombie *nzom;

	nzom = new Zombie;
	nzom->set_name(name);
	return nzom;
}
