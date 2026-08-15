
#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
	private:
		const std::string	name;
		bool				issigned;
		const int			s_grade;
		const int			e_grade;
	public:
						AForm();
						AForm(const AForm& copy);
						AForm(const std::string name, const int& sgrade, const int& egrade);
AForm&					operator=(const AForm& copy);
virtual					~AForm();
int						getSgrade()		const;
bool					getsigned()		const;
const std::string&		getname()		const;
int						getEgrade()		const;
void					beSinged(const Bureaucrat& bur);
virtual void			execute(const Bureaucrat& executor) const = 0;
			class GradeTooHighException : public std::exception {
				public:
				const char*		what() const throw();
			};

			class GradeTooLowException : public std::exception {
				public:
				const char*		what() const throw();
			};
};

std::ostream&	operator<<(std::ostream& out, const AForm& aform);

#endif
