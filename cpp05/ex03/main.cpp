
#include <Intern.hpp>

int main() {

	Bureaucrat bur("zohair", 160);
	Bureaucrat::GradeTooHighException x;

	x.what();

}
