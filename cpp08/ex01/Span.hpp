#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int>::iterator VecIt;

class Span {
	private:
		unsigned int N;
		std::vector<int> span;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& copy);
		~Span();
Span&	operator=(const Span& copy);

void	addNumber(int num);
void	addNumbers(VecIt beg, VecIt end);
int		shortestSpan();
int		longestSpan();

};

#endif
