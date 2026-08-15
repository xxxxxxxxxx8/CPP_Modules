
#ifndef CLAP_TRAP
# define CLAP_TRAP

#include <iostream>
#include <string>

class ClapTrap {
	protected:
		std::string		name;
		int 			HitPoints;
		int				EnergyPoints;
		int				Attack_damage;
	public:

					ClapTrap(const std::string& name);
					ClapTrap(const std::string& name, unsigned int Hp, unsigned int Ep, unsigned int Ad);
					ClapTrap();
					ClapTrap(const ClapTrap& copy);
		ClapTrap&	operator=(const ClapTrap& copy);
					~ClapTrap();

	virtual void	attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif
