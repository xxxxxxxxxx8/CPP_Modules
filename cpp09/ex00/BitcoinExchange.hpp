#ifndef	BITCOINEXCHANGE_HPP
#define	BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <cmath>

# define ERR std::string("ERROR: ")
# define FIELDERROR "wrong number of fields!"

# define FILENAMEERROR "filename format or name is invvalid!"
# define FILECONTENTERROR "invalid file content!"

# define POSITIVEERR "not a positive number."
# define BADIN "bad input!"
# define TOOLARGE "too large a number."

class BitcoinExchange {
	private:
		std::string						fileLoaded;
		std::map<std::string, float>	dict;

		static	std::string				errmo;

					BitcoinExchange();
					BitcoinExchange(const BitcoinExchange& copy);
BitcoinExchange&	operator=(const BitcoinExchange& copy);
	public:
					BitcoinExchange(const std::string filename);
					~BitcoinExchange();

void				loadDataBase(std::ifstream& dbFile);
bool				goodFormat(const std::string& fileExt);
void				processData();
std::list<std::string>	split(const std::string& str, char delimiter);
void				parseData(std::list<std::string> tokens);
bool				checkValue(std::string value);
bool				checkDate(std::list<std::string> date);
void				trimString(std::string & str);
bool				isPureValue(const std::string& str);
bool				isValidDate(const std::string& dateStr);
bool				checkTrim(std::list<std::string>& tokens);
};

#endif
