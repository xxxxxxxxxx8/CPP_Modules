
#include <Zombie.hpp>

int main()
{
	Zombie *homie;

	homie = newZombie("ihateeveverythingaboutyou");
	homie->announce();
	delete homie;
	randomChump("stranger");
}
