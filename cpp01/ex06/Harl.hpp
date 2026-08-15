
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
	private:

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		std::string strs[4];
	public:
		void	complain(std::string level);
		void	scale(int sc);
		Harl();
};

#endif
