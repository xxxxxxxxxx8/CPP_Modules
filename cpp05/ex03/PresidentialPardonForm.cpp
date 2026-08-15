
#include <PresidentialPardonForm.hpp>
#include <Bureaucrat.hpp>

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", 25, 5) {
	std::cout << "presidential pardon default constructor called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& _target) : AForm("presidential pardon", 25, 5), target(_target){
	std::cout << "presidential pardon parametric constructor called"<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)  : AForm("presidential pardon", 25, 5), target(copy.target) {
	std::cout << "presidential pardon copy constructor called"<<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "presidential pardon destructor called"<<std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
	std::cout << "presidential pardon copy-a operator overload function called"<<std::endl;
	AForm::operator=(copy);
	return *this;
}

void		PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	bool worth = (executor.getGrade() <= this->getEgrade());

	if (!this->getsigned())
		throw std::runtime_error("not signed");
	if (worth) {
		std::cout << target << " has been pardoned by Zaphod Beeblebrox"<<std::endl;
	} else {
		throw GradeTooLowException();
	}

}
