#include <ABC.hpp>

int main() {

	std::cout << "EX02 TESTS:\t"<<std::endl;
	identify(0);
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(*generate());
	identify(*generate());
	identify(*generate());
	identify(*generate());
	identify(*generate());
	identify(new Base());
	identify(*new Base());
}
