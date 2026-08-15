
#include <DiamondTrap.hpp>

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

DiamondTrap::DiamondTrap() : ClapTrap("punto_clap_name", 100, 50, 30), name("punto") {
	std::cout << "DiamondTrap default constuctor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy), name(copy.name) {
	std::cout << "DiamondTrap copy constuctor called\n";
}

DiamondTrap::DiamondTrap(const std::string& _name) : ClapTrap(_name + "_clap_name", 100, 50, 30), name(_name){
	std::cout << "DiamondTrap parametric constructor called\n";
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& copy) {
	std::cout << "DiamondTrap copy assigment operator overload function called\n";
	if (this != &copy) {
		this->ClapTrap::name = copy.ClapTrap::name;
		this->name = copy.name;
		this->Attack_damage = copy.Attack_damage;
		this->HitPoints = copy.HitPoints;
		this->EnergyPoints = copy.EnergyPoints;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called\n";
}

void			DiamondTrap::whoAmI() {
	std::cout << "D_name: "<<name<<" clap_name: "<<ClapTrap::name<<'\n';
}
