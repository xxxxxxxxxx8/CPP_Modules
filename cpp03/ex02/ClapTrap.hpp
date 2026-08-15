
#ifndef CLAP_TRAP
# define CLAP_TRAP

#include <iostream>
#include <string>

class ClapTrap {
	protected:
		std::string		name;
		unsigned int 	HitPoints;
		unsigned int	EnergyPoints;
		unsigned int	Attack_damage;
	public:

						ClapTrap(const std::string& name);
						ClapTrap(const std::string& name, unsigned int Hp, unsigned int Ep, unsigned int Ad);
						ClapTrap();
						ClapTrap(const ClapTrap& copy);
		ClapTrap&		operator=(const ClapTrap& copy);
		virtual			~ClapTrap();

		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif
