
#include <AForm.hpp>
#include <Bureaucrat.hpp>

AForm::AForm() : name("default"), issigned(false), s_grade(3), e_grade(3) {
	std::cout << "AForm default constructor called"<< std::endl;
}

AForm::AForm(const AForm& copy) :
name(copy.name), issigned(copy.issigned), s_grade(copy.s_grade), e_grade(copy.e_grade)
{
	std::cout << "AForm copy constructor called"<<std::endl;
	if (s_grade > 150 || e_grade > 150)
		throw GradeTooLowException();
	if (s_grade < 1 || e_grade < 1)
		throw GradeTooHighException();
}

AForm::AForm(const std::string _name, const int& sgrade, const int& egrade) :
name(_name), issigned(false), s_grade(sgrade), e_grade(egrade)
{
	std::cout << "AForm parametric constructor called"<<std::endl;
	if (s_grade > 150 || e_grade > 150)
		throw GradeTooLowException();
	if (s_grade < 1 || e_grade < 1)
		throw GradeTooHighException();
}

AForm::~AForm() {
	std::cout << "AForm destructor called"<<std::endl;
}

AForm&	AForm::operator=(const AForm& copy) {
	std::cout << "copy assignment operator overload function called"<<std::endl;
	if (&copy != this) {
		this->issigned = copy.issigned;
	}
	return *this;
}

int		AForm::getSgrade()		const {
	return s_grade;
}

int		AForm::getEgrade()		const {
	return e_grade;
}

bool					AForm::getsigned()		const {
	return issigned;
}

const std::string&		AForm::getname()		const {
	return name;
}

std::ostream&	operator<<(std::ostream& out, const AForm& aform) {
	out << "AForm INFO: 	\n";
	out <<	"\tname: " << aform.getname() <<\
			"\n\tis signed: "<< (aform.getsigned() ? "True" : "false")<<\
			"\n\tgrade required to sign: "<< aform.getSgrade()<<\
			"\n\tgrade required to exec: "<< aform.getEgrade();
	return out;
}

const char*		AForm::GradeTooHighException::what() const throw() {
	return "AForm: grade is too high";
}

const char*		AForm::GradeTooLowException::what() const throw() {
	return "AForm: grade is too low";
}

void			AForm::beSinged(const Bureaucrat& bur) {
	if (bur.getGrade() <= s_grade) {
		this->issigned = true;
	} else {
		throw GradeTooLowException();
	}
}
