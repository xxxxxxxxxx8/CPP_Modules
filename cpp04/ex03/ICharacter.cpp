
#include  <ICharacter.hpp>

ICharacter::ICharacter() {
	std::cout << "ICharacter default constructor called\n";
}

ICharacter::~ICharacter() {
	std::cout << "ICharacter destructor called\n";
}

ICharacter::ICharacter(const ICharacter& copy) {
	(void)copy;
	std::cout << "ICharacter copy constructor called\n";
}

ICharacter&	ICharacter::operator=(const ICharacter& copy) {
	(void)copy;
	std::cout << "ICharacter copy assignment operator overload function called\n";
	return *this;
}
