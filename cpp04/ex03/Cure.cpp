
#include <Cure.hpp>

Cure::Cure() : AMateria("cure") {
	std::cout << "default constructor of Cure called\n";
}

Cure::Cure(const Cure& copy) : AMateria(copy) {
	std::cout << "copy constructor of Cure called\n";
}

Cure::~Cure() {
	std::cout << "Destructor of Cure called\n";
}

Cure&	Cure::operator=(const Cure& copy) {
	std::cout << "copy assignment operator overload function called\n";
	if (&copy != this) {
		this->type = copy.type;
	}
	return *this;
}

AMateria*	Cure::clone() const {
	return new Cure(*this);
}

void		Cure::use(ICharacter& target) {
	std::cout << "* heals "<< target.getName() <<"’s wounds *\n";

}
