#include <BitcoinExchange.hpp>

std::string BitcoinExchange::errmo = "error in format!";

BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::BitcoinExchange(std::string filename) {
	std::ifstream inFile(filename.c_str());
	std::ifstream dbFile("data.csv");

	if (!dbFile.is_open()) throw std::runtime_error("databaseFile didnt open!");
	size_t	dotPos = filename.find('.');
	if (dotPos == std::string::npos || !goodFormat(filename.substr(dotPos)))
		throw std::runtime_error(FILENAMEERROR);
	else {
		if (!std::getline(inFile, fileLoaded, '\0'))
			throw std::runtime_error(FILECONTENTERROR);
		loadDataBase(dbFile);
		processData();

	}

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	static_cast<void>(copy);
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& copy) {
	static_cast<void>(copy);
	return *this;
}

BitcoinExchange::~BitcoinExchange() {

}

bool	BitcoinExchange::goodFormat(const std::string& fileExt) {
	return fileExt == ".csv" || fileExt == ".txt" ? true : false;
}

bool	BitcoinExchange::checkDate(std::list<std::string> date) {
	static_cast<void>(date);
	return true;
}

bool	BitcoinExchange::checkValue(std::string value) {
	static_cast<void>(value);
	return true;
}

void	BitcoinExchange::parseData(std::list<std::string> tokens) {

	if (!isValidDate(*tokens.begin()) || !isPureValue(*(++tokens.begin()))) {

		std::cout << ERR + errmo << std::endl; errmo = "invalid content.";
		return ;
	} else  {
		std::map<std::string, float>::iterator found =  dict.find(*tokens.begin());
		if (found == dict.end()) {
			found = dict.lower_bound(*tokens.begin());
			found = found != dict.begin() ? --found : found;
		}
		float res = atof((++tokens.begin())->c_str()) * found->second;
		std::cout << *tokens.begin() << " => " << *(++tokens.begin()) << " = " << res << std::endl;
	}
}

bool	BitcoinExchange::checkTrim(std::list<std::string>& tokens) {

	errmo = "[ ]";
	if (tokens.empty() || tokens.size() != 2) return false;

	std::string tok1 = *(tokens.begin());
	std::string tok2 = *(++tokens.begin());
	size_t s2(0); size_t s1(tok1.size() - 1);

	if (tok1.empty() || tok2.empty()) return errmo = "" ,false;

	for (;s1 > 0 && isspace(tok1[s1]);--s1);

	for (;s2 < tok2.size() && isspace(tok2[s2]);++s2);

	if (isspace(tok1[0]) || isspace(tok2[tok2.size() - 1])) return false;

	trimString(*(++tokens.begin()));
	trimString(*(tokens.begin()));

	return s2 == 1 && tok1.size() - 1 -  s1 == 1;
}

void	BitcoinExchange::processData() {

	std::istringstream			stream(fileLoaded);
	std::string					line;
	std::list<std::string>	tokens;

	std::getline(stream, line);
	if (line != "date | value") {
		std::cerr << "invalid format!" << std::endl;
		return ;
	}

	while (std::getline(stream, line)) {

		tokens	=	split(line, '|');
		if (!checkTrim(tokens)) {
			std::cerr << ERR + "invalid token(s) => " + errmo << std::endl;
			continue ;
		}
		parseData(tokens);
	}
}

void		BitcoinExchange::trimString(std::string & str) {

	size_t s(0), e(str.size() - 1);

	while (s < str.size() && isspace(str[s]))
		s++;
	while (e > s && isspace(str[e]))
		e--;
	str = str.substr(s, e - s + 1);
}

void	BitcoinExchange::loadDataBase(std::ifstream& dbFile)
{
	std::string				line;
	std::list<std::string>	tokens;

	std::getline(dbFile, line);
	if ("date,exchange_rate" != line)
		throw std::runtime_error("database dataForm is invalid!");
	while (std::getline(dbFile, line)) {
		tokens = split(line, ',');
		if (tokens.size() != 2) throw std::runtime_error("database dataForm is invalid!");
		dict[*tokens.begin()] = atof((++tokens.begin())->c_str());
	}
}

std::list<std::string> BitcoinExchange::split(const std::string& str, char delimiter) {
    std::list<std::string>	tokens;
    std::string				token;

    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == delimiter) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else
            token += str[i];
    }

    if (!token.empty()) {
        tokens.push_back(token);
    }

    return tokens;
}

bool	BitcoinExchange::isPureValue(const std::string& str) {

	errmo = "bad input => " + str;
    if (str.empty())
		return errmo = BADIN, false;
    if (str[0] == '-')
		return errmo = POSITIVEERR, false;
	bool dotted = false;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            if (dotted) return  false;
            dotted = true;
        } else if (!std::isdigit(str[i])) {
            return errmo = str, false;
        }
    }

	if ("." == str) return false;

	double value = std::atof(str.c_str());
	errmo = TOOLARGE;
    return value >= 0.0 && value <= 1000.0;
}

bool	BitcoinExchange::isValidDate(const std::string& dateStr) {

	std::list<int> leapYears; leapYears.push_back(2012);
	leapYears.push_back(2016); leapYears.push_back(2020); leapYears.push_back(2024);

	errmo = "bad input => " + dateStr;
	std::string yTok, mTok, dTok;
	if (dateStr.length() != 10) return false;
    if (dateStr[4] != '-' || dateStr[7] != '-') return false;

    yTok = dateStr.substr(0, 4);
    mTok = dateStr.substr(5, 2);
    dTok = dateStr.substr(8, 2);

	errmo = std::string(BADIN) + " => " + dateStr;
    for (size_t i(0); i < yTok.size(); i++) if (!isdigit(yTok[i])) return false;
    for (size_t i(0); i < mTok.size(); i++) if (!isdigit(mTok[i])) return false;
    for (size_t i(0); i < dTok.size(); i++) if (!isdigit(dTok[i])) return false;

	ssize_t	y(atoi(yTok.c_str())), m(atoi(mTok.c_str())), d(atoi(dTok.c_str()));
	std::list<int>::iterator it = std::find(leapYears.begin(), leapYears.end(), y);
	bool leapedYear = (it != leapYears.end() ? true : false);
	if ((m == 2 && d > 29) || (!leapedYear && m == 2 && d > 28)) return false;

    return y > 2008 && y < 2026 && m > 0 && m < 13 && d > 0 && d < 32;
}
