
#include <ScavTrap.hpp>

ScavTrap::ScavTrap(const std::string& n)
: ClapTrap(n, 100, 50, 20)
{
	std::cout << "ScavTrap Paramteric constructor called\n";
}

ScavTrap::ScavTrap()
: ClapTrap("Nobody", 100, 50, 20)
{
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& copy)
: ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& copy) {
	ClapTrap::operator=(copy);
	std::cout<<"ScavTrap copy assignment operator overload called!\n";
	return *this;
}

void	ScavTrap::guardGate()
{
	if (EnergyPoints <= 0 || HitPoints <= 0) {
		std::cout <<"The energy points are low\n";
		return ;
	}
	std::cout << "ScavTrap is now in Gate keeper mode.\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (EnergyPoints <= 0 || HitPoints <= 0) {
		std::cout <<"The energy points are low\n";
		return ;
	}
	EnergyPoints	-=1;
	std::cout<<"ScavTrap "<<name<<" attacks "<<target<<", causing "<<Attack_damage<<" points of damage!\n";
}
