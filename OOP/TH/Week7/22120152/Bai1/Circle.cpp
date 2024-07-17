#include "Circle.h"
Circle::Circle() : Shape("Circle") {
	name = "Circle";
	R = 0;
	C.X = C.Y = 0;
}
Circle::Circle(double radius) : Shape("Circle") {
	R = radius;
	C.X = C.Y = 0;
}
Circle::Circle(Point c, double radius) : Shape("Circle") {
	C = c;
	R = radius;
}
double Circle::CalArea() {
	return R * R * 3.14;
}
bool Circle::IsSelected(Point src) {
	return distance(src, C) < R;
}
Circle::Circle(const Circle& c):Shape("Circle") {
	this->R = c.R;
	this->C = c.C;
}
Circle& Circle::operator=(const Circle& src) {
	if (this != &src) {
		C = src.C;
		R = src.R;
	}
	return *this;
}