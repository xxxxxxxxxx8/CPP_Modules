
#include <Form.hpp>
#include <Bureaucrat.hpp>

Form::Form() : name("default"), issigned(false), s_grade(3), e_grade(3) {
	std::cout << "Form default constructor called"<< std::endl;
}

Form::Form(const Form& copy) :
name(copy.name), issigned(copy.issigned), s_grade(copy.s_grade), e_grade(copy.e_grade)
{
	std::cout << "Form copy constructor called"<<std::endl;
	if (s_grade > 150 || e_grade > 150)
		throw GradeTooLowException();
	if (s_grade < 1 || e_grade < 1)
		throw GradeTooHighException();
}

Form::Form(const std::string _name, const int& sgrade, const int& egrade) :
name(_name), issigned(false), s_grade(sgrade), e_grade(egrade)
{
	std::cout << "Form parametric constructor called"<<std::endl;
	if (s_grade > 150 || e_grade > 150)
		throw GradeTooLowException();
	if (s_grade < 1 || e_grade < 1)
		throw GradeTooHighException();
}

Form::~Form() {
	std::cout << "Form destructor called"<<std::endl;
}

Form&	Form::operator=(const Form& copy) {
	std::cout << "copy assignment operator overload function called"<<std::endl;
	if (&copy != this) {
		this->issigned = copy.issigned;
	}
	return *this;
}

int		Form::getSgrade()		const {
	return s_grade;
}

int		Form::getEgrade()		const {
	return e_grade;
}

bool					Form::getsigned()		const {
	return issigned;
}

const std::string&		Form::getname()		const {
	return name;
}

std::ostream&	operator<<(std::ostream& out, const Form& form) {
	out << "FORM INFO: 	\n";
	out <<	"\tname: " << form.getname() <<\
			"\n\tis signed: "<< (form.getsigned() ? "True" : "false")<<\
			"\n\tgrade required to sign: "<< form.getSgrade()<<\
			"\n\tgrade required to exec: "<< form.getEgrade();
	return out;
}

const char*		Form::GradeTooHighException::what() const throw() {
	return "Form: grade is too high";
}

const char*		Form::GradeTooLowException::what() const throw() {
	return "Form: grade is too low";
}

void			Form::beSinged(const Bureaucrat& bur) {
	if (bur.getGrade() <= s_grade) {
		this->issigned = true;
	} else {
		throw GradeTooLowException();
	}
}
