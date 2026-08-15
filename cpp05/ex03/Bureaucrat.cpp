
#include <Bureaucrat.hpp>
#include <AForm.hpp>

Bureaucrat::Bureaucrat() : name("dahira"), grade(42) {
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& _name, int _grade) : name(_name) {
	std::cout << "Bureaucrat parametric constructor called" << std::endl;
	if (_grade > 0 && _grade < 151) {
		grade = _grade;
	} else {
		if (_grade > 150)
			throw Bureaucrat::GradeTooLowException();
		throw Bureaucrat::GradeTooHighException();
	}
}

Bureaucrat::~Bureaucrat() {
		std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name), grade(copy.grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat&			Bureaucrat::operator=(const Bureaucrat& copy) {
	std::cout << "Bureaucrat copy assignment operator overload function called" << std::endl;
	if (&copy != this) {
		this->grade = copy.grade;
	}
	return *this;
}

const std::string&	Bureaucrat::getName() const {
	return name;
}

int 	Bureaucrat::getGrade() const {
	return grade;
}

std::ostream&	operator<<(std::ostream &out, const Bureaucrat& obj) {
	out << obj.getName() << ", bureaucrat grade "<< obj.getGrade() << '.';
	return out;
}

void		Bureaucrat::increment() {
	if (grade > 1) {
		grade--;
	} else {
		throw Bureaucrat::GradeTooHighException();
	}
}

void		Bureaucrat::decrement() {
	if (grade < 150) {
		grade++;
	} else {
		throw Bureaucrat::GradeTooLowException();
	}
}

const char*		Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat: grade is too high";
}

const char*		Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat: grade is too low";
}

void			Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSinged(*this);
		std::cout << this->name << " signed "<<form.getname()<<std::endl;
	} catch (const std::exception& x) {
		std::cout << this->name << " couldn't sign "<<form.getname()<<" because ==> "<< x.what()<<std::endl;
	}
}

void		Bureaucrat::executeForm(const AForm& form)	const {
	try {
		form.execute(*this);
		std::cout <<name<<" executed "<<form.getname()<<std::endl;
	} catch (const std::exception& x) {
		std::cerr <<name<< " couldn't execute '"<<form.getname()<<"' form because ==> "<<x.what()<<std::endl;
	}
}

void		Bureaucrat::setGrade(int _grade) {
	grade = _grade;
}
