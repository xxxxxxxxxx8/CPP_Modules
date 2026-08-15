
#include <Point.hpp>

double	ft_abs(double x) {
    return (x < 0) ? -x : x;
}

double Tarea(double x1, double y1, double x2, double y2, double x3, double y3) {
    return ft_abs((x1 * y2 - y1 * x2) + (x2 * y3 - y2 * x3) + (x3 * y1 - y3 * x1)) / 2;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{

	double	abc = Tarea(a.get_x().toFloat(), a.get_y().toFloat(), b.get_x().toFloat(), \
				      b.get_y().toFloat(), c.get_x().toFloat(), c.get_y().toFloat());

	double	abp = Tarea(a.get_x().toFloat(), a.get_y().toFloat(), b.get_x().toFloat(), \
				      b.get_y().toFloat(), point.get_x().toFloat(), point.get_y().toFloat());

	double	bcp = Tarea(b.get_x().toFloat(), b.get_y().toFloat(), c.get_x().toFloat(), c.get_y().toFloat(), \
					  point.get_x().toFloat(), point.get_y().toFloat());

	double	cpa = Tarea(c.get_x().toFloat(), c.get_y().toFloat(), point.get_x().toFloat(), point.get_y().toFloat(), \
					a.get_x().toFloat(), a.get_y().toFloat());

			abc = roundf(abc);

	int 	sum = roundf(cpa + bcp + abp);

	return sum == abc && bcp && cpa && abp;
}
