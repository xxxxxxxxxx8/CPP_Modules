
#include <Zombie.hpp>

void	Zombie::announce( void ) const
{
	std::cout << name <<" : BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string nm)
{
	name = nm;
}
