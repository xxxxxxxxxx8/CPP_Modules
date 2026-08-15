
#include <Cat.hpp>

Cat::Cat() : Animal("Cat") {
	std::cout << "Default Constructor of Cat called\n";
}
Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << "Copy Constructor of Cat called\n";
}

Cat::~Cat() {
	std::cout << "Copy Destructor of Cat called\n";
}

Cat&	Cat::operator=(const Cat& copy) {
	std::cout << "Copy assignment operator overloaded of Cat called\n";
	Animal::operator=(copy);
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Meooow\n";
}
