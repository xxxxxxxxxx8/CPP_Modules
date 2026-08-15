
#include  <Animal.hpp>

Animal::Animal() : type("Animal"){
	std::cout << "Default Constructor of Animal called\n";
}

Animal::Animal(const std::string& name) : type(name){
	std::cout << "Parametric Constructor of Animal called\n";
}
Animal::Animal(const Animal& copy) : type(copy.type) {
	std::cout << "Copy Constructor of Animal called\n";
}

Animal::~Animal() {
	std::cout << "Copy Destructor of Animal called\n";
}

Animal&	Animal::operator=(const Animal& copy) {
	std::cout << "Copy assignment operator overloaded of Animal called\n";
	type = copy.type;
	return *this;
}

const std::string&	Animal::getType() const {
	return type;
}

void	Animal::makeSound() const {
	std::cout << "shouldnt know ur class was a game\n";
}
