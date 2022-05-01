#ifndef POINT_H
#define POINT_H
class Point {
private:
	double x, y,z;
public:
	Point(double x = 0, double y = 0, double z = 0);
	Point(Point const&& p);
	Point(Point const& p);
	Point& operator = (Point p);
	friend std::ostream& operator << (std::ostream& out, const Point& p);
	bool operator > (Point& p);
	bool operator == (Point& p);
	bool operator < (Point& p);
	bool operator () (Point& p);
	bool operator < (const Point& p);
	double module();
	~Point();
};
#endif
