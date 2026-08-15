
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <ScavTrap.hpp>
#include <FragTrap.hpp>

class DiamondTrap :  public ScavTrap, public FragTrap {
	private:
		std::string name;
	public:
				DiamondTrap();
				DiamondTrap(const DiamondTrap &copy);
				DiamondTrap(const std::string& name);
DiamondTrap&	operator=(const DiamondTrap& copy);
				~DiamondTrap();
	void		attack(const std::string& target);
	void		whoAmI();
};

#endif
