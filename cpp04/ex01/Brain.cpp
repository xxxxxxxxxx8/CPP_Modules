
#include <Brain.hpp>

Brain::Brain() {
	std::cout << "Brain default constructor called\n";
	for (int i(0); i < 100; i++) {
		ideas[i] = "Not his idea";
	}
}

Brain::Brain(const Brain& copy) {
	for (int i(0); i < 100; i++) {
		ideas[i] = copy.ideas[i];
	}
	std::cout << "Brain copy constructor called\n";
}

Brain::~Brain() {
	std::cout << "Brain destructor called\n";
}

Brain&		Brain::operator=(const Brain& copy) {
	std::cout << "Brain copy assignment operator overload function called\n";
	if (&copy != this) {
		for (int i(0); i < 100; i++) {
			ideas[i] = copy.ideas[i];
		}
	}
	return *this;
}
