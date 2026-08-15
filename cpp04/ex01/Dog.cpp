
#include <Dog.hpp>

Dog::Dog() : Animal("Dog") {
	brain = new Brain();
	std::cout << "Default Constructor of Dog called\n";
}
Dog::Dog(const Dog& copy) : Animal(copy) {
	brain = copy.brain ? (new Brain(*copy.brain)) : NULL;
	std::cout << "Copy Constructor of Dog called\n";
}

Dog::~Dog() {
	std::cout << "Destructor of Dog called\n";
	delete brain;
}

Dog&	Dog::operator=(const Dog& copy) {
	std::cout << "Copy assignment operator overloaded of Dog called\n";
	Animal::operator=(copy);
	if (&copy != this) {
		brain ? (delete brain) : (void)1;
		brain = copy.brain ? (new Brain(*copy.brain)) : NULL;
	}
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "bark! bark!\n";
}
