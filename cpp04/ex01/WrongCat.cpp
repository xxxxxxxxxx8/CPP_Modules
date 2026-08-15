
#include <WrongCat.hpp>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "Default Constructor of WrongCat called\n";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
	std::cout << "Copy Constructor of WrongCat called\n";
}

WrongCat::~WrongCat() {
	std::cout << "Destructor of WrongCat called\n";
}

WrongCat&	WrongCat::operator=(const WrongCat& copy) {
	std::cout << "Copy assignment operator overloaded of WrongCat called\n";
	WrongAnimal::operator=(copy);
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "WrongMeow\n";
}
