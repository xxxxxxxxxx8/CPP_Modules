
#include <Harl.hpp>

Harl::Harl()
{
	strs[0] = "debug";
	strs[1] = "info";
	strs[2] = "error";
	strs[3] = "warning";
}

void	Harl::debug( void )
{
	std::cout << "[ --Debug-- ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ --Info-- ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
	std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ --Warning-- ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ --Error-- ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	typedef void (Harl::*Funcs)( void ) ;
	Funcs	fn[4];

	fn[0] = &Harl::debug;
	fn[1] = &Harl::info;
	fn[3] = &Harl::error;
	fn[2] = &Harl::warning;
	int	i = -1;

	while (level != strs[++i]);
	if (i != -1 && i < 4)
		(this->*fn[i])();
	else
		std::cout << "level can't be found\n";
}
