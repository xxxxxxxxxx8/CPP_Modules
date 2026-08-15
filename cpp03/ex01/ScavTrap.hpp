
#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include <ClapTrap.hpp>

class ScavTrap : public ClapTrap {
	public:
				ScavTrap(const std::string& name);
				ScavTrap(const ScavTrap& copy);
				ScavTrap();
	ScavTrap&	operator=(const ScavTrap& copy);
				~ScavTrap();
		void	guardGate();
		void	attack(const std::string& target);
};

#endif
