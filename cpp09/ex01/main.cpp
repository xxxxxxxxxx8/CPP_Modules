#include <RPN.hpp>

int main (int ac, char **av) {

	if (ac == 2)  {
		try {

			RPN		rpn(av[1]);

		} catch (const std::exception& x) {
			std::cerr << x.what() << std::endl;
		}
	} else {
		std::cerr << "Error: Usage: " << av[0] << " <Expression>" << std::endl;
	}

}
