
#include <PhoneBook.hpp>

int main()
{
	PhoneBook	pbook;
	std::string	s;

	while (true) {
		std::cout << "Enter a command: ";
		if (!std::getline(std::cin, s))
			return exit(1), 1;
		if (s == "ADD") {
			pbook.add_contact();
		}
		else if (s == "SEARCH") {
			if (!pbook.display()) {
				std::cout << "you have an empty pbook\n";
				std::cout << "recommendation: use [ADD] command below to add a contact\n";
				continue ;
			}
			std::cout << "Enter a contact index: ";
			std::string index;
			std::getline(std::cin, index);
			try {
				pbook.search(std::stoi(index));
			} catch (std::exception&) {
				std::cerr << "invalid index input\n";
			}
		}
		else if (s == "EXIT")
			return (0);
	}
	return 0;
}
