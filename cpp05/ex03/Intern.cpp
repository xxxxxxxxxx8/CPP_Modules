
#include <Intern.hpp>

Intern::Intern() {
	std::cout << "Intern default constructor called"<<std::endl;
}

Intern::Intern(const Intern& copy) {
	(void)copy;
	std::cout << "Intern copy constructor called"<<std::endl;

}

Intern::~Intern() {
	std::cout << "Intern copy destructor called"<<std::endl;
}

Intern&		Intern::operator=(const Intern& copy) {
	(void)copy;
	std::cout << "Intern copy-a operator overloadFunction called"<<std::endl;
	return *this;
}

int		Intern::enumerating(const std::string& FName) {
	int 		index(0);
	std::string	strs[] = {"presidential pardon", "robotomy request", \
						  "shrubbery creation", "Not found"};
	for (; index < 3 && (strs[index] != FName); index++) {}
	return index;
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) {
	AForm	*ptr;

	try {

		switch (this->enumerating(formName)) {
			case 0:
				ptr = new PresidentialPardonForm(target);
				std::cout << "Intern creates presidential pardon form"<<std::endl;
				break ;
			case 1:
				ptr = new RobotomyRequestForm(target);
				std::cout << "Intern creates robotomy request form"<<std::endl;
				break ;
			case 2:
				ptr = new ShrubberyCreationForm(target);
				std::cout << "Intern creates shrubbery creation form"<<std::endl;
				break ;
			default:
				throw std::runtime_error("form not found");
		}
	} catch (const std::exception& x) {
		std::cerr << "Intern couldn't make form because ==> " << x.what() <<std::endl;
		throw;
	}
	return ptr;
}
