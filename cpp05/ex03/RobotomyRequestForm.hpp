
#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP

#include <AForm.hpp>

class RobotomyRequestForm : public AForm {
	private:
		const std::string target;
	public:
						RobotomyRequestForm();
						RobotomyRequestForm(const std::string& _target);
						RobotomyRequestForm(const RobotomyRequestForm& copy);
						~RobotomyRequestForm();
RobotomyRequestForm&	operator=(const RobotomyRequestForm& copy);
void					execute(const Bureaucrat& executor) const;
};

#endif
