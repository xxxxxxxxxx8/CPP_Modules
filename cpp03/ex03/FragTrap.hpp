
#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include <ClapTrap.hpp>

class FragTrap : virtual public ClapTrap {
	public:
				FragTrap();
				FragTrap(const FragTrap& copy);
				FragTrap(const std::string& name);
	FragTrap&	operator=(const FragTrap& copy);
				~FragTrap();
		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif
