#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <limits.h>

class  ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);

	public:
static void		convert(std::string value);

ScalarConverter&	operator=(const ScalarConverter& copy);
					~ScalarConverter();
};

std::string		trim(const std::string& str);
bool			isNan(double value);
int				isInf(double value);
std::string		to_lower(std::string str);
bool			isValidNum(std::string& str);

#endif
