
#include <ClapTrap.hpp>

void ClapTrap::attack(const std::string& target)
{
	if (EnergyPoints <= 0 || HitPoints <= 0) {
		std::cout <<"The energy points are low\n";
		return ;
	}
	EnergyPoints	-=1;
	std::cout<<"ClapTrap "<<name<<" attacks "<<target<<", causing "<<Attack_damage<<" points of damage!\n";
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (EnergyPoints <= 0 || HitPoints <= 0) {
		std::cout <<"The energy points | HitPoints are low\n";
		return ;
	}
	std::cout <<amount<<" damage received!\n";
	HitPoints = (HitPoints - amount > 0) ? HitPoints - amount : 0;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (EnergyPoints <= 0 || HitPoints <= 0) {
		std::cout <<"The energy points | HitPoints are low\n";
		return ;
	}
	std::cout <<amount<<" amount repaired!\n";
	EnergyPoints-=1;
	HitPoints+=amount;
}

ClapTrap::ClapTrap() : HitPoints(10), EnergyPoints(10), Attack_damage(0) {
	std::cout<<"ClapTrap default constructor called!\n";
}

ClapTrap::ClapTrap(const ClapTrap& copy)
: name(copy.name), HitPoints(copy.HitPoints),
				   EnergyPoints(copy.EnergyPoints),
				   Attack_damage(copy.Attack_damage)
{
	std::cout<<"ClapTrap copy constructor called!\n";
}

ClapTrap::~ClapTrap() {
	std::cout<<"ClapTrap destructor called!\n";
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& copy) {
	std::cout<<"ClapTrap copy assignment operator overload called!\n";
	if (this != &copy) {
		this->name = copy.name;
		this->Attack_damage = copy.Attack_damage;
		this->EnergyPoints = copy.EnergyPoints;
		this->HitPoints = copy.HitPoints;
	}
	return *this;
}

ClapTrap::ClapTrap(const std::string& n)
: name(n), HitPoints(10), EnergyPoints(10), Attack_damage(0)
{
	std::cout << "ClapTrap Paramteric 1 constructor called\n";
}

ClapTrap::ClapTrap(const std::string& n, unsigned int Hp, unsigned int Ep, unsigned int Ad)
: name(n), HitPoints(Hp), EnergyPoints(Ep), Attack_damage(Ad)
{
	std::cout << "ClapTrap Paramteric 2 constructor called\n";
}
