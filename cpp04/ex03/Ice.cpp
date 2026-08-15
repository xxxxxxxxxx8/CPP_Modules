
#include <Ice.hpp>

Ice::Ice() : AMateria("ice") {
	std::cout << "default constructor of Ice called\n";
}

Ice::Ice(const Ice& copy) : AMateria(copy) {
	std::cout << "copy constructor of Ice called\n";
}

Ice::~Ice() {
	std::cout << "Destructor of Ice called\n";
}

Ice&	Ice::operator=(const Ice& copy) {
	std::cout << "copy assignment operator overload function called\n";
	if (&copy != this) {
		this->type = copy.type;
	}
	return *this;
}

AMateria*	Ice::clone() const {
	return new Ice(*this);
}

void		Ice::use(ICharacter& target) {
	std::cout <<  "* shoots an ice bolt at "<<target.getName() <<" *\n";

}
