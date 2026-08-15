
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	int					fixed_value;
	static const int	fract;
public:
			Fixed();
			Fixed(const int value);
			Fixed(const float value);
			Fixed(const Fixed &copy);
	float	toFloat() const;
	int		toInt() const;
			~Fixed();
	Fixed&	operator=(Fixed const &copy);

	bool			operator!=(const Fixed &copy) const;
	bool			operator==(const Fixed &copy) const;
	bool			operator>(const Fixed &copy) const;
	bool			operator<(const Fixed &copy) const;
	bool			operator>=(const Fixed &copy) const;
	bool			operator<=(const Fixed &copy) const;

	Fixed	operator+(const Fixed &copy);
	Fixed	operator-(const Fixed &copy);
	Fixed	operator*(const Fixed &copy);
	Fixed	operator/(const Fixed &copy);

	Fixed	operator++();
	Fixed	operator++(int);
	Fixed	operator--();
	Fixed	operator--(int);
	int 	getRawBits( void ) const;
	void 	setRawBits( int const raw );
	static Fixed&		min(Fixed &fp1, Fixed &fp2);
	static const Fixed&	min(const Fixed &fp1, const Fixed &fp2);
	static Fixed&		max(Fixed &fp1, Fixed &fp2);
	static const Fixed&	max(const Fixed &fp1, const Fixed &fp2);

};

std::ostream&	operator<<(std::ostream& op, const Fixed &fp);

#endif
