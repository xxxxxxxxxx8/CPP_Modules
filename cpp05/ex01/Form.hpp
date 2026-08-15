
#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;
class Form {
	private:
		const std::string	name;
		bool				issigned;
		const int			s_grade;
		const int			e_grade;
	public:
						Form();
						Form(const Form& copy);
						Form(const std::string name, const int& sgrade, const int& egrade);
Form&					operator=(const Form& copy);
						~Form();
int						getSgrade()		const;
bool					getsigned()		const;
const std::string&		getname()		const;
int						getEgrade()		const;
void					beSinged(const Bureaucrat& bur);
			class GradeTooHighException : public std::exception {
				public:
				const char*		what() const throw();
			};

			class GradeTooLowException : public std::exception {
				public:
				const char*		what() const throw();
			};
};

std::ostream&	operator<<(std::ostream& out, const Form& form);

#endif
