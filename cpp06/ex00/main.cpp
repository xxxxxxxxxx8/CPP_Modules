#include <ScalarConverter.hpp>

int main(int ac, char **av) {
	static_cast<void>(ac);

	ScalarConverter::convert(av[1]);
}
