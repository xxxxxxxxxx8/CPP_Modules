
#include <Fixed.hpp>

const int	Fixed::fract = 8;

Fixed::Fixed() : fixed_value(0){
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &copy) {
	this->fixed_value = copy.fixed_value;
	std::cout << "Copy constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << '\n';
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	return fixed_value;
}

void Fixed::setRawBits( int const raw ) {

	fixed_value = raw;
	std::cout << "setRawBits member function called\n";
}

Fixed&	Fixed::operator=(const Fixed &copy) {
	this->fixed_value = copy.fixed_value;
	std::cout << "Copy assignment operator called\n";
	return *this;
}
