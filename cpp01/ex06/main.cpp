
#include <Harl.hpp>

int	enm(std::string s)
{
	if (s == "debug")
		return (0);
	else if (s == "info")
		return (1);
	else if (s == "warning")
		return (2);
	else if (s == "error")
		return (3);
	return 1337;
}

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cerr << "invalid number of arguments\n";
		std::cerr << "Usage: ./program [Level's name]\n";
	}
	std::string s(av[1]);
	Harl		cpl;

	switch (enm(s))
	{
		case 0:
			cpl.scale(0);
			break ;
		case 1:
			cpl.scale(1);
			break ;
		case 2:
			cpl.scale(2);
			break ;
		case 3:
			cpl.scale(3);
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
