#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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
#include <deque>
#include <utility>
#include <sys/time.h>
#include <iomanip>
#include <limits.h>
#include <errno.h>

typedef struct timeval timeStamps;

#define OUTSERROR "invalid token!"

class PmergeMe {

	private:
			std::vector<int>					intsVec;
			std::deque<int>						intsDeq;

				PmergeMe();
				PmergeMe(const PmergeMe& copy);
PmergeMe&		operator=(const PmergeMe& copy);

	public:
				PmergeMe(char **av, int ac);
				~PmergeMe();

	void									parseArguments(char **av, int ac);
	std::vector<int>						sortVec(std::vector<int> ints);
	std::vector<std::pair<int, int> >		makePairs(std::vector<int> ints);
	std::deque<int>							sortDeq(std::deque<int> ints);
	std::deque<std::pair<int, int> >		makePairs(std::deque<int> ints);
	std::vector<int>						jacobing(int n);

};

#endif
