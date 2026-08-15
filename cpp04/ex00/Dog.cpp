
#include <Dog.hpp>

Dog::Dog() : Animal("Dog") {
	std::cout << "Default Constructor of Dog called\n";
}
Dog::Dog(const Dog& copy) : Animal(copy) {
	std::cout << "Copy Constructor of Dog called\n";
}

Dog::~Dog() {
	std::cout << "Copy Destructor of Dog called\n";
}

Dog&	Dog::operator=(const Dog& copy) {
	std::cout << "Copy assignment operator overloaded of Dog called\n";
	Animal::operator=(copy);
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "bark! bark!\n";
}
