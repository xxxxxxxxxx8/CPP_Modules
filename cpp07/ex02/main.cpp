#include <Array.hpp>
#include <vector>

int main () {
	std::vector<int> vec;

	vec.size();
	Array<int> arr(10);

	arr[0] = 1337;
	arr[9] = 1338;

	for (unsigned int i(0); i < arr.size(); i++)
		std::cout << arr[i] << std::endl;

}
