#include <Iter.hpp>
#include <iostream>

void	uppin(int* c) {
	std::cout << c++ << '\n';
}

int main()
{
	int  arr[3] = {1, 1, 1};
	iter(&arr, (size_t)1, uppin);
	for (int i(0); i < 3; i++) {
		std::cout << arr[i] << std::endl;
	}

    return 0;
}
