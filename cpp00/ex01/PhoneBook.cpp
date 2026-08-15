
#include <PhoneBook.hpp>

PhoneBook::PhoneBook(): index(0), fg(false)
{
}

bool	Contact::is_usd() {
	return is_used;
}

void	Contact::set_usd() {
	is_used = true;
}

Contact::Contact()
{
	is_used = false;
	first_name = "Empty";
	last_name = "Empty";
	nickname = "Empty";
	darkest_secret = "Empty";
	phone_number = "Empty";
}

void	PhoneBook::search(int ind)
{
	if (ind < 1 || ind > 8)
		std::cerr << "index is out of range" << std::endl;
	else {
		if (contacts[ind - 1].is_usd()) {
			std::cout << "F_NAME: " << contacts[ind - 1].first_name << std::endl;
			std::cout << "L_NAME: " << contacts[ind - 1].last_name << std::endl;
			std::cout << "NICKNAME: " << contacts[ind - 1].nickname << std::endl;
			std::cout << "D_SECRET: " << contacts[ind - 1].darkest_secret << std::endl;
			std::cout << "P_NUMBER: " << contacts[ind - 1].phone_number << std::endl;
		}
		else {
			std::cerr << "This index's contact is empty!" << std::endl;
		}
	}
}

bool	PhoneBook::display()
{
	bool	f = false;

	std::cout << "|     index     f_name     l_name     n_name|\n";
	for (int i = 0; i < 8; i++) {
		if (contacts[i].is_usd()) {
			std::cout << std::setw(10) << i + 1;
			std::cout << "|";
			std::cout << std::setw(10) << truncate(contacts[i].first_name);
			std::cout << "|";
			std::cout << std::setw(10) << truncate(contacts[i].last_name);
			std::cout << "|";
			std::cout << std::setw(10) << truncate(contacts[i].nickname);
			std::cout << '\n';
			f = true;
		}
	}
	return f;
}

bool	PhoneBook::valid_input(std::string prompt, std::string& str)
{
	std::string input;
	bool		flag = false;
	bool		ispc = false;

	std::cout << prompt;
	if (!std::getline(std::cin, input))
		exit(1);
	for (size_t i = 0; i < input.length(); ++i) {
		if (!isprint(input[i])) {
			flag = true;
			break ;
		}
		if (isspace(input[i])) {
			continue ;
		}
		else {
			ispc = true;
		}
	}
	flag || input == "" || !ispc ? valid_input(prompt, str) : true;
	!fg ? str = input, fg = true : true;
	return false;
}

void	PhoneBook::add_contact()
{

	fg = valid_input("first name: ", contacts[index % 8].first_name);
	fg = valid_input("last name: ", contacts[index % 8].last_name);
	fg = valid_input("nickname: ", contacts[index % 8].nickname);
	fg = valid_input("phone number: ", contacts[index % 8].phone_number);
	fg = valid_input("darkest_secret: ", contacts[index % 8].darkest_secret);
	contacts[index % 8].set_usd();
	index++;
	index = index % 8;
}

std::string PhoneBook::truncate(std::string str)
{
	std::string temp;
	int 		i;

	i = 0;
	if (str.length() > 10) {
		while (temp.length() < 9)
			temp += str[i++];
		temp += '.';
		return (temp);
	}
	return (str);
}
