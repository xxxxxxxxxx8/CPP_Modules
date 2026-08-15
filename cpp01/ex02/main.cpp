
#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string &ref = str;
	std::string *pstr = &str;

	std::cout << "String:\t\t~|" << str << std::endl;
	std::cout << "its ref:\t~|" << ref << std::endl;
	std::cout << "its address:\t~|" << pstr << std::endl;
}
