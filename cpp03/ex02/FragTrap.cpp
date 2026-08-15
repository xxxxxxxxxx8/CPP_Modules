
#include <FragTrap.hpp>

FragTrap::FragTrap()
: ClapTrap("nobody", 100, 100, 30)
{
	std::cout<<"FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string& n)
: ClapTrap(n, 100, 100, 30)
{
	std::cout<<"FragTrap parametric constructor called\n";
}

FragTrap::~FragTrap() {
	std::cout<<"FragTrap destructor called\n";
}

FragTrap::FragTrap(const FragTrap& copy)
: ClapTrap(copy)
{
	std::cout<<"ClapTrap copy constructor called!\n";
}

void FragTrap::attack(const std::string& target)
{
	if (EnergyPoints <= 0 || HitPoints <= 0) {
		std::cout <<"The energy points are low\n";
		return ;
	}
	EnergyPoints	-=1;
	std::cout<<"FragTrap "<<name<<" attacks "<<target<<", causing "<<Attack_damage<<" points of damage!\n";
}

void	FragTrap::highFivesGuys(void) {
	if (EnergyPoints <= 0 || HitPoints <= 0) {
		std::cout <<"The energy points are low\n";
		return ;
	}
	std::cout << "Hiiigh fiiiive?!\n";
}

FragTrap&	FragTrap::operator=(const FragTrap& copy) {
	ClapTrap::operator=(copy);
	std::cout<<"FragTrap copy assignment operator overload called!\n";
	return *this;
}
