
#include  <WrongAnimal.hpp>

WrongAnimal::WrongAnimal() : type("WrongAnimal"){
	std::cout << "Default Constructor of WrongAnimal called\n";
}

WrongAnimal::WrongAnimal(const std::string& name) : type(name){
	std::cout << "Parametric Constructor of WrongAnimal called\n";
}
WrongAnimal::WrongAnimal(const WrongAnimal& copy) : type(copy.type) {
	std::cout << "Copy Constructor of WrongAnimal called\n";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor of WrongAnimal called\n";
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& copy) {
	std::cout << "Copy assignment operator overloaded of WrongAnimal called\n";
	type = copy.type;
	return *this;
}

const std::string&	WrongAnimal::getType() const {
	return type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "shouldnt know ur class was a game\n";
}
