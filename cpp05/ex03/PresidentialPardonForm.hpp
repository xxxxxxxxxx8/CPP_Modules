
#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

#include <AForm.hpp>

class PresidentialPardonForm : public AForm {
	private:
		const std::string target;
	public:
						PresidentialPardonForm();
						PresidentialPardonForm(const std::string& _target);
						PresidentialPardonForm(const PresidentialPardonForm& copy);
						~PresidentialPardonForm();
PresidentialPardonForm&	operator=(const PresidentialPardonForm& copy);
void					execute(const Bureaucrat& executor) const;
};

#endif
