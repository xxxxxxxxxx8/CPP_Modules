
#include <Point.hpp>

Point::Point() : x(0), y(0){

}

Point::Point(float const fx, float const fy) : x(fx), y(fy){

}

Point::Point(Point const& copy) :x(copy.x), y(copy.y) {

}

Point&	Point::operator=(Point const &copy) {
	this != &copy ? *this = copy : copy;
	return (*this);
}

Point::~Point() {

}

Fixed const	Point::get_x() const
{
	return x;
}

Fixed const	Point::get_y() const
{
	return y;
}
