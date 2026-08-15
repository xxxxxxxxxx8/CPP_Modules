#include <ScalarConverter.hpp>

std::string	floating(const std::string& val)
{
	std::string			vl(val); vl = trim(vl);
	std::ostringstream	out;
	std::istringstream	in(val);
	std::string			postfix("f");

	if (to_lower(vl)=="nan" || to_lower(vl)=="inf" \
	|| to_lower(vl)=="-inf" || to_lower(vl)=="+inf"\
	|| to_lower(vl)=="nanf" || to_lower(vl)=="+inff"
	|| to_lower(vl)=="-inff" || to_lower(vl)=="inff") {
		if ("nanf" == to_lower(vl) || to_lower(vl)=="+inff" \
		|| to_lower(vl)=="-inff" || to_lower(vl)=="inff")
			vl.erase(vl.size() - 1);
		return to_lower(vl) + "f";
	}
	else {
		if (vl.size() == 1 && !isdigit(vl[0])) {
			out << static_cast<float>(vl[0]);
			vl = out.str()+"f";
		}
		if (!isValidNum(vl)) return "impossible";
		float res; in  >> res;
		float tmp = res - static_cast<int>(res);

		if ((tmp < 1e-6 || tmp > 1e-6) && vl.find(".") == std::string::npos) postfix = ".0f";
	}
	double check = atof(vl.c_str());
	if (isNan(check)) return "nanf";
	if (isInf(check) == 1) return "inff";
	if (isInf(check) == -1) return "-inff";
	return vl + postfix;
}

std::string	doubling(const std::string& val)
{
	std::string			vl(val); vl = trim(vl);
	std::ostringstream	out;
	std::istringstream	in(val);
	std::string			postfix;

	if (to_lower(vl)=="nan" || to_lower(vl)=="inf" \
	|| to_lower(vl)=="-inf" || to_lower(vl)=="+inf"\
	|| to_lower(vl)=="nanf" || to_lower(vl)=="+inff"
	|| to_lower(vl)=="-inff" || to_lower(vl)=="inff") {
		if ("nanf" == to_lower(vl) || to_lower(vl)=="+inff" \
		|| to_lower(vl)=="-inff" || to_lower(vl)=="inff")
			vl.erase(vl.size() - 1);
		return to_lower(vl);
	}
	else {
		if (vl.size() == 1 && !isdigit(vl[0])) {
			out << static_cast<float>(vl[0]);
			vl = out.str();
		}
		if (!isValidNum(vl)) return "impossible";
		double res; in  >> res;
		double tmp = std::abs(res) - std::abs(static_cast<int>(res));
		if ((tmp < 1e-6 || tmp > 1e-6) && vl.find(".") == std::string::npos) postfix = ".0";
	}
	double check = atof(vl.c_str());
	if (isNan(check)) return "nan";
	if (isInf(check) == 1) return "inf";
	if (isInf(check) == -1) return "-inf";
	return vl + postfix;
}

std::string	inting(const std::string& val) {
	std::string			vl(val); vl = trim(vl);
	std::ostringstream	out;

	if (vl.size() == 1 && !isdigit(vl[0])) {
		out << static_cast<int>(vl[0]);
		vl = out.str(); out.str("");
	}
	if (!isValidNum(vl)) return "impossible";

	if (vl.find(".") != std::string::npos)
		vl = vl.substr(0, vl.find("."));

	long longInt = atol(vl.c_str());
	if (longInt > INT_MAX || longInt < INT_MIN)
		return "impossible";
	out << longInt; vl = out.str();
	return vl;
}

std::string charing(const std::string& val) {

	if (inting(val) == "impossible")
		return "impossible";
	int value =  atoi(inting(val).c_str());
	if (value > CHAR_MAX || value < CHAR_MIN)
		return "impossible";
	if (!(value > 31 && value < 127))
		return "Non displayable";
	return std::string("'") + static_cast<char>(value) + "'";
}

void	ScalarConverter::convert(std::string val) {
	static_cast<void>(val);
	if (val.empty()) {
		std::cout << "char:	Non displayable"<< std::endl;
		std::cout << "int:	0"<< std::endl;
		std::cout << "float:	0.0f"<<std::endl;
		std::cout << "double:	0.0"<< std::endl;
		return;
	}

	std::cout << "char:	"<< charing(val) << std::endl;
	std::cout << "int:	"<< inting(val) << std::endl;
	std::cout << "float:	"<< floating(val) << std::endl;
	std::cout << "double:	"<< doubling(val) << std::endl;

}

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	static_cast<void>(copy);
}

ScalarConverter::~ScalarConverter() {

}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& copy) {
	static_cast<void>(copy);
	return *this;
}
