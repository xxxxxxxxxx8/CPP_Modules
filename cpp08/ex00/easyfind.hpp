#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
int	easyfind(T container, int occ) {

	typename T::iterator it =  std::find(container.begin(), container.end(), occ);
	return it == container.end() ? -1 : *it;
}

#endif
