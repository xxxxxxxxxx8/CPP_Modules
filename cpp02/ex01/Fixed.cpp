
#include <Fixed.hpp>

const int	Fixed::fract = 8;

Fixed::Fixed() : fixed_value(0){
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called\n";
	this->fixed_value = copy.fixed_value;
}

Fixed::Fixed(const int value) : fixed_value(value << fract) {
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float value) : fixed_value(roundf(value * (1 << fract))) {
	std::cout << "Float constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << '\n';
}

Fixed&	Fixed::operator = (const Fixed &copy) {
	std::cout << "Copy assignment operator called\n";
	this->fixed_value = copy.fixed_value;
	return *this;
}

float	Fixed::toFloat() const {
	return fixed_value / (float)(1  << fract);
}

int	Fixed::toInt() const {
	return fixed_value >> fract;
}

std::ostream&	operator << (std::ostream& op, const Fixed &fp) {
	op << fp.toFloat();
	return op;
}

int Fixed::getRawBits( void ) const {
	return fixed_value;
}

void Fixed::setRawBits( int const raw ) {

	fixed_value = raw;
}
