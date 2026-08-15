#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <class TSWAP>

void	swap (TSWAP& var1, TSWAP& var2) {
	TSWAP tmp	=	var1;
	var1	=	var2;
	var2	=	tmp;
}

template <class TMIN>

TMIN&	min (TMIN& value1, TMIN& value2) {
	return value1 < value2 ? value1 : value2;
}

template <class TMAX>

TMAX&	max (TMAX& value1, TMAX& value2) {
	return value1 > value2 ? value1 : value2;
}

#endif
