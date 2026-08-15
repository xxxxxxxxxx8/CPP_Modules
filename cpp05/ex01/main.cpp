
#include <Bureaucrat.hpp>
#include <Form.hpp>

int main() {

try {
	try {
		Bureaucrat bur("arrakid", 44);
		Form form("milf lghiyab", 1, 22);
		std::cout << form << std::endl;
		bur.signForm(form);
		std::cout << form << std::endl;
	} catch (std::exception &x) {
		throw ;
	}
} catch (std::exception& x) {
	std::cout << x.what() << std::endl;
}

}
