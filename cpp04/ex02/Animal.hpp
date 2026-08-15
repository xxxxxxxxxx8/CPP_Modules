
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
					Animal();
					Animal(const std::string& name);
					Animal(const Animal& copy);
					virtual
					~Animal();
Animal&				operator=(const Animal& copy);
const std::string&	getType() const;
virtual
void				makeSound() const = 0;
};

#endif
