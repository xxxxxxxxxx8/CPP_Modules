
#ifndef ZOMBIE_HPP2
# define ZOMBIE_HPP2

#include <string>
#include <iostream>

class Zombie {

	private:
		std::string name;
	public:
		void	announce( void ) const;
		void	set_name( std::string nm );

};

Zombie* zombieHorde( int N, std::string name );

#endif
