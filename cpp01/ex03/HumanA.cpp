
#include <HumanA.hpp>

HumanA::HumanA(std::string sname, Weapon& weap)
: name(sname), wp(weap)
{

}

void	HumanA::attack() const
{
	std::cout << name << " attacks with their " << wp.getType() << std::endl;
}
