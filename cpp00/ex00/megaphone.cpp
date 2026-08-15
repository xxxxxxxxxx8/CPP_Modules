#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cerr << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (1);
	}

	for (int arg = 1; arg < ac; ++arg) {
		std::string s(av[arg]);
		for (size_t i(0); i < s.length(); ++i){
			s[i] = toupper(s[i]);
		}
		std::cout << s;
	}
	std:: cout << std::endl;
	return 0;
}
