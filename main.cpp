#include <iostream>
#include "set.cpp"
#include "Point.h"

int main()
{
	Set<int> a;
	a.insert(5);
	a.insert(-4);
	a.insert(5);
	a.insert(9);
	a.insert(8);
	std::cout << a << std::endl;
	std::cout << a.find(-4) << std::endl;
	std::cout << a.find(-3) << std::endl;
	a.erase(9);
	a.erase(10);
	a.erase(8);
	a.erase(5);
	
	std::cout << a << std::endl;
	a.erase(34);
	std::cout << a.find(-4) << std::endl;
	std::cout << a << std::endl;

	std:: cout << a.find(-4) << std::endl;
	std::cout << a.size() << std::endl;
	Set<int> b;
	Set<int> c;
	b.insert(6);
	c.insert(9);
	Set <int> d = b.intersect(c);
	std::cout << b << std::endl << c << std::endl << d << std:: endl;
	std::cout << "___________________________________________________" << std::endl;

	Set<double> da;
	da.insert(5.2);
	Set<double> db;
	try {
		Set<double> dc = da.intersect(db);
	}
	catch (const char*s) {
		std::cout << s << std::endl;
	}
	catch (...){ 
		std::cout << "Unknow Exeption!" << std::endl; 
	}
	std::cout << "___________________________________________________" << std::endl;

	Set<Point> P;
	P.insert(Point(3, 4, 5));
	P.insert(Point(9, 7, 8));
	P.insert(Point(3, 4, 5));
	std::cout << "Find:" << P.find(Point(3, 4, 5)) << std::endl;
	std::cout << P.find(Point(0, 4, 5)) << std::endl;
	std::cout << P.size() << std::endl;
	Set<Point> V;
	V.insert(Point(3, 4, 5));
	V.insert(Point(1, 2, 3));
	Set <Point> L = P.intersect(V);
	std::cout << P << std::endl << V << std::endl << L << std::endl;

}
// erase find binary 
//std:: algorithm Библиотека