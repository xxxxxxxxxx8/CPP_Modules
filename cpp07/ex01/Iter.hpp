#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <class TARR ,class TFUN>

void	iter (TARR arr, size_t len, TFUN fun) {
	size_t it(0);

	if (arr && fun) {
		while (it < len) {
			fun(arr[it++]);
		}
	}
}

#endif
