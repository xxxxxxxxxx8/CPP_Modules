
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

Fixed::Fixed(const float value) : fixed_value(round(value * (1 << fract))) {
	std::cout << "Float constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << '\n';
}

Fixed&	Fixed::operator = (Fixed const &copy) {
	std::cout << "Copy assignment operator called\n";
	this->fixed_value = copy.fixed_value;
	return *this;
}

float	Fixed::toFloat() const {
	return (float)fixed_value / (1  << fract);
}

int	Fixed::toInt() const {
	return fixed_value >> fract;
}

std::ostream&	operator << (std::ostream& op, Fixed const &fp) {
	op << fp.toFloat();
	return op;
}

bool	Fixed::operator!=(const Fixed &copy) const {
	return copy.fixed_value != this->fixed_value;
}

bool	Fixed::operator==(const Fixed &copy) const {
	return copy.fixed_value == this->fixed_value;
}

bool	Fixed::operator>(const Fixed &copy) const {
	return this->fixed_value > copy.fixed_value;
}

bool	Fixed::operator<(const Fixed &copy) const {
	return this->fixed_value < copy.fixed_value;
}

bool	Fixed::operator>=(const Fixed &copy) const {
	return this->fixed_value >= copy.fixed_value;
}

bool	Fixed::operator<=(const Fixed &copy) const {
	return this->fixed_value <= copy.fixed_value;
}

Fixed	Fixed::operator+(const Fixed &copy) {
	return Fixed(this->fixed_value + copy.fixed_value);
}

Fixed	Fixed::operator-(const Fixed &copy) {
	return Fixed(this->fixed_value - copy.fixed_value);
}

Fixed	Fixed::operator*(const Fixed &copy) {
	Fixed tmp = Fixed(0);
	tmp.setRawBits(this->fixed_value * copy.fixed_value / (1<<fract));
	return tmp;
}

Fixed	Fixed::operator/(const Fixed &copy) {
	Fixed tmp = Fixed(0);
	if (copy.fixed_value == 0) {
		std::cerr << "division by [0] error\n";
		tmp.setRawBits(-1);
		return tmp;
	}
	tmp.setRawBits(this->fixed_value / copy.fixed_value * (1<<fract));
	return tmp;
}

Fixed	Fixed::operator++() {
	this->fixed_value += 1;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);

	this->fixed_value += 1;
	return tmp;
}

Fixed	Fixed::operator--() {
	this->fixed_value -= 1;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);
	this->fixed_value -= 1;
	return tmp;
}

int Fixed::getRawBits( void ) const {
	return fixed_value;
}

void Fixed::setRawBits( int const raw ) {

	fixed_value = raw;
}

Fixed&		Fixed::min(Fixed &fp1, Fixed &fp2)
{
	return fp1 < fp2 ? fp1 : fp2;
}

const Fixed&	Fixed::min(Fixed const  &fp1, Fixed const  &fp2)
{
	return fp1 < fp2 ? fp1 : fp2;
}

Fixed&		Fixed::max(Fixed &fp1, Fixed &fp2)
{
	return fp1 > fp2 ? fp1 : fp2;
}

const Fixed&	Fixed::max(const Fixed &fp1, const Fixed &fp2)
{
	return fp1 > fp2 ? fp1 : fp2;
}
