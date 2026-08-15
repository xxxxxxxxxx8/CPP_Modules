
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
	float	toFloat() const;
	int		toInt() const;
			~Fixed();
	Fixed&	operator=(const Fixed &copy);
			Fixed(const Fixed &copy);
	int 	getRawBits( void ) const;
	void 	setRawBits( int const raw );
};

std::ostream&	operator<<(std::ostream& op, const Fixed &fp);
#endif
