
#include <HumanB.hpp>

HumanB::HumanB(std::string sname) : name(sname)
{
}

HumanB::HumanB() : name("None"), wp(0)
{
}

void	HumanB::setWeapon(Weapon& weap)
{
	wp = &weap;
}

void	HumanB::attack()
{
	Weapon tmp;

	!wp ? wp = &tmp : wp;
	std::cout << name << " attacks with their " << wp->getType() << std::endl;
}
