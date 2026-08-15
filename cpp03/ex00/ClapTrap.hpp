
#ifndef CLAP_TRAP
# define CLAP_TRAP

#include <iostream>
#include <string>

class ClapTrap {
		std::string name;
		int 	HitPoints;
		int		EnergyPoints;
		int		Attack_damage;
	public:

					ClapTrap();
					ClapTrap(const std::string& name);
					ClapTrap(const ClapTrap& copy);
		ClapTrap&	operator=(const ClapTrap& copy);
					~ClapTrap();

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif
