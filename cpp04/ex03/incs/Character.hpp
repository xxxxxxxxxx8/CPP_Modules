
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <ICharacter.hpp>

class Character : public ICharacter {
	private:
		std::string		name;
		AMateria		*items[4];

	public:
				Character();
				Character(const std::string& _name);
				Character(const Character& copy);
				~Character();
Character&		operator=(const Character& copy);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

};

#endif
