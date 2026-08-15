
#include <IMateriaSource.hpp>

IMateriaSource::IMateriaSource() {
	std::cout << "IMateriaSource default constructor called\n";
}

IMateriaSource::IMateriaSource(const IMateriaSource& copy) {
	(void)copy;
	std::cout << "IMateriaSource copy constructor called\n";
}

IMateriaSource::~IMateriaSource() {
	std::cout << "IMateriaSource destructor called\n";
}

IMateriaSource&	IMateriaSource::operator=(const IMateriaSource& copy) {
	(void)copy;
	std::cout << "IMateriaSource copy assignment operator called\n";
	return *this;
}
