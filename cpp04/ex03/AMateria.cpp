
#include <AMateria.hpp>
#include <iostream>

AMateria::AMateria(std::string const & _type) : type(_type) {
	std::cout << "Amateria parametric constructor called but useless\n";
}

std::string const & AMateria::getType() const {
	return type;
}

AMateria::AMateria() {
	std::cout << "AMateria default constructor called\n";
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called\n";
}

AMateria::AMateria(AMateria const& copy) : type(copy.type) {
	std::cout << "AMateria copy constructor called\n";
}

void	AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "just an abstract class function should not have any role!\n";
}

AMateria&			AMateria::operator=(const AMateria& copy) {
	std::cout << "Copy assignment operator overloading function called\n";
	if (&copy != this) {
		this->type = copy.type;
	}
	return *this;
}
