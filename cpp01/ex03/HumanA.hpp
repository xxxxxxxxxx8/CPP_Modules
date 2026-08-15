
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <Weapon.hpp>
#include <string>

class HumanA {
	private:
		std::string name;
		Weapon 		&wp;
	public:
		HumanA(std::string sname, Weapon &weap);
		void	attack() const;
};

#endif
