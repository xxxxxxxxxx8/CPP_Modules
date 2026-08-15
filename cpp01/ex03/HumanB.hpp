
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <Weapon.hpp>
#include <string>

class HumanB {
	private:
		std::string name;
		Weapon 		*wp;
	public:
		HumanB(std::string sname);
		HumanB();
		void	setWeapon(Weapon& weap);
		void	attack();
};

#endif
