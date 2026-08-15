
#include <Bureaucrat.hpp>

int main() {

	Bureaucrat bur;
	Bureaucrat buri("milionaire", 3);

	std::cout << bur << std::endl;
	std::cerr << bur << std::endl;
	try {
		Bureaucrat bur_("taj", 150);
		bur_.decrement();
	} catch (std::exception &x) {
		std::cout << x.what() << '\n';
	}
	std::cout << buri << std::endl;
	buri = bur;
	std::cout << buri << std::endl;
}
