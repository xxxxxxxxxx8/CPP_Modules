
#include <RobotomyRequestForm.hpp>
#include <Bureaucrat.hpp>

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45) {
	std::cout << "robotomy request default constructor called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& _target) : AForm("robotomy request", 72, 45), target(_target){
	std::cout << "robotomy request parametric constructor called"<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)  : AForm("robotomy request", 72, 45), target(copy.target) {
	std::cout << "robotomy request copy constructor called"<<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "robotomy request destructor called"<<std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	std::cout << "robotomy request copy-a operator overload function called"<<std::endl;
	AForm::operator=(copy);
	return *this;
}

void		RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	static int fifty;

	if (!this->getsigned())
		throw std::runtime_error("not signed");
	if (executor.getGrade() <= this->getEgrade()) {
		std::cout << "ZZZzzzzTTTT... DRRRRRRRR... GZZZZZZZT...\n" << std::endl;
		if (fifty % 2)
			std::cout <<target<< " has been robotomized successfully" << std::endl;
		else
			std::cout << "the robotomy failed!"<<std::endl;
		++fifty;
	} else {
		throw GradeTooLowException();
	}
}
