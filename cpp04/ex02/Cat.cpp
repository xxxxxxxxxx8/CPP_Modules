
#include <Cat.hpp>

Cat::Cat() : Animal("Cat") {
	std::cout << "Default Constructor of Cat called\n";
	brain = new Brain();
}
Cat::Cat(const Cat& copy) : Animal(copy) {
	brain = new Brain(*copy.brain);
	std::cout << "Copy Constructor of Cat called\n";
}

Cat::~Cat() {
	std::cout << "Destructor of Cat called\n";
	delete brain;
}

Cat&	Cat::operator=(const Cat& copy) {
	std::cout << "Copy assignment operator overloaded of Cat called\n";
	Animal::operator=(copy);
	if (&copy != this) {
		delete brain;
		brain = new Brain(*copy.brain);
	}
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Meooow\n";
}
