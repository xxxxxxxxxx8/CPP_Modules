
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <ICharacter.hpp>

class AMateria
{
	protected:
		std::string type;
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const& copy);

	public:
		virtual				~AMateria();

		std::string const 	& getType() const;
		virtual AMateria* 	clone() const = 0;
		virtual void		use(ICharacter& target);
		AMateria&			operator=(const AMateria& copy);
};

#endif
