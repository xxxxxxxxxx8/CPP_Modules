
#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>

class Contact{
	public:
		std::string first_name;
		std::string last_name;
		std::string	nickname;
		std::string	darkest_secret;
		std::string phone_number;
		Contact();
		bool	is_usd();
		void	set_usd();
	private:
		bool	is_used;
};

class PhoneBook{
	public:
		Contact contacts[8];
		PhoneBook();
		void	search(int ind);
		bool	display();
		void	add_contact();
	private:
		std::string truncate(std::string str);
		bool		valid_input(std::string prompt, std::string& str);
		int			index;
		bool		fg;

};

#endif
