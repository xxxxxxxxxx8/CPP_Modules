#include <BitcoinExchange.hpp>

#include <iostream>

int main (int ac, char **av) {

	if (2 == ac) {
		try {

			std::cout.precision(10);
			BitcoinExchange exchange(av[1]);

		} catch (const std::exception &x) {
			std::cerr << "Error: " << x.what() << std::endl;
			return 1;
		}
	} else {
		std::cerr << "Error: Usage: " << av[0] << " <filename>" << std::endl;
		return 1;
	}
	return 0;
}
