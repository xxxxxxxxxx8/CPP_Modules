
#include <DiamondTrap.hpp>

int main()
{
    DiamondTrap p1("zaghba");
	ClapTrap *p = new FragTrap();

	p->attack("jaija");
	delete p;
    DiamondTrap p2(p1);

	std::cout<<p1.getName()<<'\n';
	std::cout<<p2.getName()<<'\n';
	p1.whoAmI();
	p2.whoAmI();

}
