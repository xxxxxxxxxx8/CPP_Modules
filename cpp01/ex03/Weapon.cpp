
#include <Weapon.hpp>

Weapon::Weapon()
{
	type = "Desmond Thomas Doss Weapon";
}

Weapon::Weapon(std::string in)
{
	type = in;
}

const std::string& Weapon::getType() {
	return (type);
}

void	Weapon::setType(std::string t_name) {
	type = t_name;
}
