#include <Span.hpp>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span span = Span(5);
	int arr [] = {6, 3, 17, 9, 11};
	std::vector<int> vec(arr, arr + 5);
	span.addNumbers(vec.begin(), vec.end());
	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;
	return 0;
}
