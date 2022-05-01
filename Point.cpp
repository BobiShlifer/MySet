#include <iostream>
#include <math.h>
#include "Point.h"
//#include "get_value.h"
Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}
Point::Point(Point const& p) : x(p.x), y(p.y), z(p.z) {}
Point::Point(Point const&& p) : x(p.x), y(p.y), z(p.z) {}
Point& Point::operator = (Point p) {
	if (&p == this)
		return *this;
	x = p.x;
	y = p.y;
	z = p.z;
	return *this;
}
std::ostream& operator << (std::ostream& out, const Point& p)
{
	out << "[" << p.x << "," << p.y << ","<< p.z << "]";
	return out;
}

double Point::module()
{
	return (sqrt(x * x + y * y + z * z));
}

bool Point::operator > (Point& p)
{
	return (module() > p.module());
}
bool Point::operator () (Point& p)
{
	return (module() < p.module());
}
bool Point::operator == (Point& p)
{
	return (module() == p.module());
}
bool Point::operator < (Point& p)
{
	return (module() < p.module());
}
bool Point::operator < (const Point& p)
{
	return (module() < Point(p).module());
}

Point::~Point() {}