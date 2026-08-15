#include <PmergeMe.hpp>

int main (int ac, char **av) {

	if (ac > 1)  {
		try {
			PmergeMe	solution(av + 1, ac - 1);
			std::cout << std::setprecision(10);

		} catch (const std::exception &x) {
			std::cerr << x.what() << std::endl;
		}
	} else {
		std::cerr << "Error: Usage: " << av[0] << " arg1 arg2 [...arg(n+1)]" << std::endl;
	}

}
