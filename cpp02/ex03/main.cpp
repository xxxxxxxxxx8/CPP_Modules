
#include <Point.hpp>

int main( void ) {

	Point a(0, 0);
	Point b(5, 0);
	Point c(2, 5);
	Point p(2, 2);
	std::cout << "is inside: " << bsp(a, b, c, p) << '\n';
	return 0;
}
