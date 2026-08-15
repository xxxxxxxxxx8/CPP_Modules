
#include <Zombie.hpp>

int main()
{
	Zombie *homie;

	homie = zombieHorde(10, "Ohrb");
	for (int i = 0; i < 10; ++i) {
		homie[i].announce();
	}
	delete[] homie;
}
