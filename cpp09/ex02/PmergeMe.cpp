#include <PmergeMe.hpp>

PmergeMe::PmergeMe() {

}

PmergeMe::PmergeMe(const PmergeMe& copy) {
	static_cast<void>(copy);
}

PmergeMe&		PmergeMe::operator=(const PmergeMe& copy) {
	static_cast<void>(copy);
	return *this;
}

PmergeMe::~PmergeMe() {

}

bool	isValidInteger(std::string num) {

	if (num.empty()) return false;

	for (size_t i(0); i < num.size(); ++i)
		if (!isdigit(num[i]))
			return false;
	return true;
}

void	PmergeMe::parseArguments(char **av, int ac) {

	std::istringstream	cutter;
	std::string			tok;

	for (int index(0); index < ac; index++) {

		cutter.clear();
		cutter.str(std::string(av[index]));
		size_t outsider = cutter.str().find_first_not_of("1234567890 ");
		if (outsider != std::string::npos || cutter.str().empty())
			throw std::runtime_error(OUTSERROR);
		if (!isValidInteger(cutter.str()))
			throw std::runtime_error(OUTSERROR);
		while (cutter >> tok) {
			if (!isValidInteger(tok)) throw std::runtime_error(OUTSERROR);
			long value = strtol(tok.c_str(), NULL, 10);
			if (value > INT_MAX || value < 0 || errno == ERANGE)
				throw std::runtime_error("overflow occured or some sort of invalid value");
			intsVec.push_back(value);
		}

	}
	intsDeq.assign(intsVec.begin(), intsVec.end());
}

std::vector<int>	PmergeMe::jacobing(int n) {

	std::vector<bool>	visited(n, false);
	std::vector<int>	order;

	if (n <= 1) {
		order = n == 1 ? order.push_back(0), order : order;
		return order;
	} else {
		order.push_back(0);
		visited[0] = true;
	}

    std::vector<long>	jacobsthalSeq;

    jacobsthalSeq.push_back(1);
    jacobsthalSeq.push_back(1);

    for (;jacobsthalSeq.back() < n;)
		jacobsthalSeq.push_back(jacobsthalSeq[jacobsthalSeq.size() - 1] + 2 * jacobsthalSeq[jacobsthalSeq.size() - 2]);

	for (size_t i = 2; i < jacobsthalSeq.size(); ++i) {
        long upper_bound = std::min(jacobsthalSeq[i], (long)n);
        long lower_bound = jacobsthalSeq[i - 1];

        for (long j = upper_bound - 1; j >= lower_bound; --j) {
            if (!visited[j]) {
                order.push_back(j);
                visited[j] = true;
            }
        }
    }

    for (int k = 0; k < n; ++k)
		if (!visited[k])
			order.push_back(k);

    return order;
}

std::vector<int>	PmergeMe::sortVec(std::vector<int> ints) {

	std::vector<int>					mChain;
	std::vector<int>					pChain;
	std::vector<std::pair<int, int> >	pairs = makePairs(ints);

	if (ints.size() < 2) return ints;
	if (ints.size() == 2) {
		if (*ints.begin() > *(++ints.begin()))
			std::swap(ints[0], ints[1]);
		return ints;
	}

	int	widowed(ints.size() % 2 ? ints.back() : -1);

	for (size_t index(0); index < pairs.size(); index++) {

		if (pairs[index].first > pairs[index].second) {
			mChain.push_back(pairs[index].first);
			pChain.push_back(pairs[index].second);
			std::swap(pairs[index].first, pairs[index].second);
		} else {
			pChain.push_back(pairs[index].first);
			mChain.push_back(pairs[index].second);
		}
	}

	mChain	=	sortVec(mChain);

	for (std::vector<std::pair<int, int> >::iterator elm = pairs.begin(); elm != pairs.end(); ++elm) {

		if (mChain[0] == elm->second)  {
			mChain.insert(mChain.begin(), elm->first);
            std::vector<int>::iterator	element = std::find(pChain.begin(), pChain.end(), elm->first);
			if (element != pChain.end())
				pChain.erase(element);
			break ;
		}
	}

	std::vector<int>	insertOrder = jacobing(pChain.size());

	for (size_t i = 0; i < insertOrder.size(); ++i) {
		size_t	index = insertOrder[i];
		std::vector<int>::iterator insertPoint = std::lower_bound(mChain.begin(), mChain.end(), pChain[index]);
		mChain.insert(insertPoint, pChain[index]);
	}

	if (widowed != -1)  {
		std::vector<int>::iterator insertPoint = std::lower_bound(mChain.begin(), mChain.end(), widowed);
		mChain.insert(insertPoint, widowed);
	}
	return mChain;
}

std::deque<std::pair<int, int> >	PmergeMe::makePairs(std::deque<int> ints) {

	std::deque<std::pair<int, int> > pairs;

    for (size_t i = 0; i < ints.size() - 1; i += 2) {
        std::pair<int, int> new_pair = std::make_pair(ints[i], ints[i + 1]);
        pairs.push_back(new_pair);
    }
	return pairs;
}

std::vector<std::pair<int, int> >	PmergeMe::makePairs(std::vector<int> ints) {

	std::vector<std::pair<int, int> > pairs;

    for (size_t i = 0; i < ints.size() - 1; i += 2) {
        std::pair<int, int> new_pair = std::make_pair(ints[i], ints[i + 1]);
        pairs.push_back(new_pair);
    }
	return pairs;
}

void printVector(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void printDeque(const std::deque<int>& deq) {
    for (size_t i = 0; i < deq.size(); ++i) {
        std::cout << deq[i];
        if (i < deq.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

std::deque<int>		PmergeMe::sortDeq(std::deque<int> ints) {

	std::deque<int>					mChain;
	std::deque<int>					pChain;
	std::deque<std::pair<int, int> >	pairs = makePairs(ints);

	if (ints.size() < 2) return ints;
	if (ints.size() == 2) {
		if (*ints.begin() > *(++ints.begin()))
			std::swap(ints[0], ints[1]);
		return ints;
	}

	int	widowed(ints.size() % 2 ? ints.back() : -1);

	for (size_t index(0); index < pairs.size(); index++) {

		if (pairs[index].first > pairs[index].second) {
			mChain.push_back(pairs[index].first);
			pChain.push_back(pairs[index].second);
			std::swap(pairs[index].first, pairs[index].second);
		} else {
			pChain.push_back(pairs[index].first);
			mChain.push_back(pairs[index].second);
		}
	}

	mChain	=	sortDeq(mChain);

	for (std::deque<std::pair<int, int> >::iterator elm = pairs.begin(); elm != pairs.end(); ++elm) {

		if (mChain[0] == elm->second)  {
			mChain.insert(mChain.begin(), elm->first);
            std::deque<int>::iterator	element = std::find(pChain.begin(), pChain.end(), elm->first);
			if (pChain.end() != element)
				pChain.erase(element);
			break ;
		}
	}

	std::vector<int>	insertOrder = jacobing(pChain.size());

	for (size_t i = 0; i < insertOrder.size(); ++i) {
		size_t	index = insertOrder[i];
		std::deque<int>::iterator insertPoint = std::lower_bound(mChain.begin(), mChain.end(), pChain[index]);
		mChain.insert(insertPoint, pChain[index]);
	}

	if (widowed != -1)  {
		std::deque<int>::iterator insertPoint = std::lower_bound(mChain.begin(), mChain.end(), widowed);
		mChain.insert(insertPoint, widowed);
	}
	return mChain;
}

PmergeMe::PmergeMe(char **av, int ac) {

	timeStamps start, end;

	parseArguments(av, ac);

	std::cout << "Before: " << std::endl;
	printVector(intsVec);
	gettimeofday(&start, NULL);
	std::vector<int> res = sortVec(intsVec);
	gettimeofday(&end, NULL);
	std::cout << "After: " << std::endl;
	printVector(res);

	long seconds = end.tv_sec - start.tv_sec;
	long microseconds = end.tv_usec - start.tv_usec;
	double duration = (seconds * 1000000.0 + microseconds);
	std::cout << "Time to process a range of " << res.size() << " elements with std::vector: " << duration << " us" << std::endl;

	gettimeofday(&start, NULL);
	std::deque<int> resDeq = sortDeq(intsDeq);
	gettimeofday(&end, NULL);

	seconds = end.tv_sec - start.tv_sec;
	microseconds = end.tv_usec - start.tv_usec;
	duration = (seconds * 1000000.0 + microseconds);
	std::cout << "Time to process a range of " << res.size() << " elements with std::deque: " << duration << " us" << std::endl;

}
