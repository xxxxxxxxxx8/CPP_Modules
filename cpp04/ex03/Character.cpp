
#include <Character.hpp>
#include <Cure.hpp>
#include <Ice.hpp>
#include <Exiter.hpp>

Exiter saver;

Character::Character() : name("Mehdi")
{
	std::cout << "Character default constructor called\n";
	items[0] = NULL;
	items[1] = NULL;
	items[2] = NULL;
	items[3] = NULL;
}

Character::Character(const std::string& _name) : name(_name) {
	std::cout << "Character parametric constructor called\n";
	items[0] = NULL;
	items[1] = NULL;
	items[2] = NULL;
	items[3] = NULL;
}

Character::Character(const Character& copy) : ICharacter(copy), name(copy.name){
	std::cout << "Character copy constructor called\n";
	for (int i(0); i < 4; i++) {
		if (copy.items[i]) {
				items[i] = copy.items[i]->clone();
		}
		else
			items[i] = NULL;
	}
}

Character&	Character::operator=(const Character& copy) {
	std::cout << "Character copy assignment operator overload function called\n";
	for (int i(0); i < 4; i++) {
		if (items[i]) {
			delete items[i];
			items[i] = copy.items[i] ? copy.items[i]->clone() : NULL;
		} else {
			items[i] = copy.items[i] ? copy.items[i]->clone() : NULL;
		}
	}
	return *this;
}

Character::~Character() {
	std::cout << "Character destructor called\n";
	for (int i(0); i < 4; i++) {
		if (items[i]) {
			delete items[i];
		}
	}
}

std::string const & Character::getName() const {
	return name;
}

void	Character::equip(AMateria* m)  {
	if (NULL == m) {
		std::cerr << "equip material pointer is NULL!\n";
		return ;
	}
	ft_collector(m, "IFID");
	bool	is_full = true;
	for (int i(0); i < 4; i++) {
		if (m == items[i]) {
			return ;
		}
		if (!items[i]) {
			items[i] = m;
			is_full = false;
			break ;
		}
	}
	if(is_full)
		ft_collector(m, COLL);
}

void Character::unequip(int idx)  {
	if (idx < 4 && idx > -1) {
		if (items[idx])
			ft_collector(items[idx], COLL);
		items[idx] = NULL;
	} else {
		std::cout << "index[idx] is out of range!\n";
	}
}

void	Character::use(int idx, ICharacter& target)  {
	if (idx <= 3 && idx >= 0 && items[idx]) {
		items[idx]->use(target);
	} else {
		std::cout << "index[idx] is out of range!\n";
	}
}
