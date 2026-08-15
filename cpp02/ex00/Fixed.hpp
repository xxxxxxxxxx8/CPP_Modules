
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{

	int					fixed_value;
	static const int	fract;

public:
					Fixed();
					Fixed(const Fixed &copy);
	Fixed&			operator=(Fixed const &copy);
					~Fixed();
	int 			getRawBits( void ) const;
	void 			setRawBits( int const raw );
};

#endif
