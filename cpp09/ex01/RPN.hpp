#ifndef RPN_HPP
# define RPN_HPP

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
#include <stack>

#include <limits>

# define ARGNUMERROR "invalid number of operands!"
# define OPLIMITERROR "the operand should not exceed 10!"

class RPN {

	private:
		std::stack<double>		lifo;
		RPN();
		RPN(const RPN& copy);
		RPN&	operator=(const RPN& copy);

	public:
		RPN(std::string cli);
		~RPN();

		bool		isOp(std::string c);
		bool		areValidOperands(std::string cli);

};

#endif
