#include <Span.hpp>

Span::Span() : N(0) {
	std::cout << "Span default constructor made N{0}"<<std::endl;
}

Span::Span(unsigned int n) : N(n) {

}

Span::Span(const Span& copy) : N(copy.N), span(copy.span){

}

Span::~Span() {

}

Span&	Span::operator=(const Span& copy) {

	if (&copy != this) {
		N = copy.N;
		span = copy.span;
	}
	return *this;
}

void	Span::addNumber(int num) {
	if (span.size() < N) {
		span.push_back(num);
	} else
		throw std::runtime_error("the span is already full spanned");
}

int		Span::shortestSpan() {
	std::vector<int> shortest;

	if (span.size() < 2)
		throw std::runtime_error("the number list should be greater than 1");
	std::sort(span.begin(), span.end());
	for (std::vector<int>::iterator it = span.begin() + 1; it != span.end(); it++) {
		shortest.push_back(*it - *(it - 1));
	}
	std::sort(shortest.begin(), shortest.end());
	return shortest[0];
}

int		Span::longestSpan() {
	if (span.size() < 2)
		throw std::runtime_error("the number list should be greater than 1");
	std::sort(span.begin(), span.end());
	return abs(*(span.end() - 1) - *(span.begin()));
}

void	Span::addNumbers(VecIt beg, VecIt end) {
	for (VecIt it = beg; it != end; it++)
		span.push_back(*it);
}
