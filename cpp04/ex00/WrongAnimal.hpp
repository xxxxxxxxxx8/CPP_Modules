
#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
	public:
					WrongAnimal();
					WrongAnimal(const std::string& name);
					WrongAnimal(const WrongAnimal& copy);
					~WrongAnimal();
WrongAnimal&		operator=(const WrongAnimal& copy);
const std::string&	getType() const ;
void				makeSound() const ;
};

#endif
