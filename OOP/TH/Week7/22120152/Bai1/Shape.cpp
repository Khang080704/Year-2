#include "Shape.h"
double distance(Point A, Point B) {
	return sqrt(pow(A.X - B.X, 2) + pow(A.Y - B.Y, 2));
}
void printPoint(Point A) {
	std::cout << "(" << A.X << "," << A.Y << ")";
}
Shape::Shape(string name) {
	this->name = name;
}
Shape::Shape() {

}
string Shape::toString() {
	stringstream ss;
	ss << name << endl;
	string s = ss.str();
	return s;
}