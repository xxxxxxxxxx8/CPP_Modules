
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;
	public:
					Bureaucrat();
					Bureaucrat(const Bureaucrat& copy);
					Bureaucrat(const std::string& _name, int _grade);
					~Bureaucrat();
Bureaucrat&			operator=(const Bureaucrat& copy);
const std::string&	getName()	const;
int 				getGrade()	const;
void				setGrade(int _grade);
void				increment();
void				decrement();

		class GradeTooHighException : public std::exception {
			public:
			const char*		what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
			const char*		what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &out, const Bureaucrat& obj);

#endif
