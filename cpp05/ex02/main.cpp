
#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

int main() {

	Bureaucrat bur("arrakid", 44);
	ShrubberyCreationForm form("1337Garden");

	bur.signForm(form);
	bur.executeForm(form);

}
