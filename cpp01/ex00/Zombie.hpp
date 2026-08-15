
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {

	private:
		std::string name;
	public:
		void	announce( void ) const;
		void	set_name( std::string nm );

};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif
