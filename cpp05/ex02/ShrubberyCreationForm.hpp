
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <AForm.hpp>
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		const std::string target;
	public:
						ShrubberyCreationForm();
						ShrubberyCreationForm(const std::string& _target);
						ShrubberyCreationForm(const ShrubberyCreationForm& copy);
						~ShrubberyCreationForm();
ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& copy);
void					execute(const Bureaucrat& executor) const;
};

#endif
