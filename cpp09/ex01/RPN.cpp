#include <RPN.hpp>

RPN::RPN() {

}

RPN::RPN(const RPN& copy) {
	static_cast<void>(copy);
}

RPN&	RPN::operator=(const RPN& copy) {
	static_cast<void>(copy);
	return *this;
}

bool	RPN::isOp(std::string c) {return c == "*" || c == "+" || c == "-" || c == "/";}

bool	RPN::areValidOperands(std::string cli) {

	std::string tok;

	for (size_t i(0); i < cli.size(); i++)  {

		if (isdigit(cli[i]))  {
			int res = atoi(cli.c_str() + i);
			if (res > 9 || res < -9)
				return false;
		}
	}
	return true;

}

bool	isTokDigit(std::string str) {
	if (str.empty()) return false;
	size_t index(0);
	if (str[0] == '-' || str[0] == '+')
		index++;
	if (false == isdigit(str[index]))
		return false;
	for (; index < str.size(); index++)  {
		if (!isdigit(str[index]))
			return false ;
	}
	return true;
}

RPN::RPN(std::string cli) {
	size_t				outsider(cli.find_first_not_of("1234567890/-+* "));
	std::istringstream	stream(cli);
	double				res;

	if (std::string::npos != outsider)
		throw std::runtime_error("invalid token [ " + (std::string() + cli[outsider]) + " ]!");

	for (;stream >> cli;) {

		if (isTokDigit(cli)) {
			lifo.push(atoi(cli.c_str()));
			if (lifo.top() >= 10 || lifo.top() <= -10) throw std::runtime_error(OPLIMITERROR);
		}
		if (isOp(cli)) {
			if (lifo.size() < 2)
				throw std::runtime_error(ARGNUMERROR);

			double op2 = lifo.top();lifo.pop();
			double op1 = lifo.top();lifo.pop();

			switch (cli[0])  {
				case '*':
					res = op1 * op2;
					break ;
				case '-':
					res = op1 - op2;
					break ;
				case '/':
					if (!op2) throw std::runtime_error("Enter a valid dominator cant devide by zero!");
					res = op1 / op2;
					break ;
				case '+':
					res = op1 + op2;
					break ;
			}
			if (std::numeric_limits<double>::max() < res) throw std::runtime_error("overflow occured!");
			lifo.push(res);
		}
	}
	if (lifo.size() != 1)
		throw std::runtime_error(ARGNUMERROR);
	std::cout <<lifo.top() << std::endl;
}

RPN::~RPN() {

}
