
#include <Zombie.hpp>

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde;

	horde = new(std::nothrow) Zombie[N];
	if (!horde) {
		std::cerr << "Allocation failed" << std::endl;
	}
	for (int i = 0; i < N; ++i) {
		horde[i].set_name(name);
	}
	return horde;
}
