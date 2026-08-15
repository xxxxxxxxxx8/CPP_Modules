#include <ScalarConverter.hpp>

std::string trim(const std::string& str) {

    size_t end = str.size() - 1;
    size_t start = 0;
	while (start >= end && isspace(str[start])) start++;
    while (end > 0 && std::isspace(str[end])) {
        --end;
    }

    return str.substr(start, end + 1);
}

bool isNan(double value) {
    return value != value;
}

int	isInf(double value) {
	if (value == HUGE_VAL)
		return 1;
	else if (value == -HUGE_VAL)
		return -1;
	return 0;
}

std::string to_lower(std::string str) {
	for (size_t i(0); i < str.size(); i++) {
		if (isupper(str[i]))
			str[i] += 32;
	}
	return str;
}

#define AFTERZERO(x) (x == 46 || x == 0 || isspace(x))

bool	isValidNum(std::string& str) {
	size_t	i(0);
	while (isspace(str[i])) i++;
	if (str[i] == '+' || str[i] == '-') i++;
	if (!isdigit(str[i]) || \
	(str[i] == '0' && !AFTERZERO(str[i + 1])))
		return false;
	while (isdigit(str[i])) i++;
	if (str[i] == '.') i++;
	if (str[-1 + i] == '.' && !isdigit(str[i])) return false;
	while (isdigit(str[i])) i++;
	if (str[i] == 'f')	{
		str.erase(i, 1);
	}
	while (isspace(str[i])) i++;
	return i != str.size() ? false : true;
}
