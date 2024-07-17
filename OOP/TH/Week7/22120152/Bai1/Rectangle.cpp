#include "Rectangle.h"
Rectangle::Rectangle() : Shape("Rectangle")
{
	W = H = 0;
	X.X = X.Y = 0;
}
Rectangle::Rectangle(int w, int h) : Shape("Rectangle") {
	W = w;
	H = h;
	X.X = X.Y = 0;
}
Rectangle::Rectangle(Point x, int w, int h) : Shape("Rectangle") {
	X = x;
	W = w;
	H = h;
}
double Rectangle::CalArea() {
	return W * H;
}
Shape* Rectangle::Clone() {
	Rectangle* result = new Rectangle;
	result->X = this->X;
	result->W = this->W;
	result->H = this->H;
	return result;
}
Rectangle::Rectangle(const Rectangle& rec) :Shape("Rectangle") {
	this->H = rec.H;
	this->W = rec.W;
	this->X = rec.X;
}