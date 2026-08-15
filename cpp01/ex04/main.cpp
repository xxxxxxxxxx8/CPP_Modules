
#include <Sed.hpp>

int	len(char *av)
{
	if (!av || !*av)
		return 0;
	return 1 + len(1 + av);
}

int main(int ac, char **av)
{
	if (ac != 4) {
		std::cerr << "invalid number of arguments" << std::endl;
		std::cerr << "Usage: ./program [infile] [s1] [s2]" << std::endl;
		return 1;
	}
	std::ifstream	ifile(av[1]);
	std::ofstream	outf("jack.replace");
	std::string		s;
	std::getline(ifile, s, '\0');
	size_t ps = s.find(av[2], 0);
	size_t length2 = len(av[2]);
	size_t length3 = len(av[3]);
	size_t allen = ps;
	while (ps != std::string::npos) {
		s.erase(ps, length2);
		s.insert(ps, av[3]);
		ps = s.find(av[2], allen);
		allen = ps + length3;
	}
	outf << s;
}
