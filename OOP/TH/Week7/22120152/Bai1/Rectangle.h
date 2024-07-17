#pragma once
#include "Shape.h"
class Rectangle :public Shape
{
protected:
	Point X; //toạ độ góc trái trên
	double W, H; //chiều rộng và chiều cao
public:
	//Constructors
	// Overriding Shape class’s IsSelected method
	Rectangle();
	Rectangle(int w, int h);
	Rectangle(Point x, int w, int h);
	Rectangle(const Rectangle& rec);
	bool IsSelected(Point p) {
		return ((p.X >= X.X) && (p.X <= X.X + W)
			&& (p.Y >= X.Y) && (p.Y <= X.Y + H));
	}
	// Overriding Shape class’s Clone method
	Shape* Clone();
	//Tính diện tích 
	double CalArea();
	void print() {
		std::cout << getName() << endl;
		std::cout << "Toa do goc trai tren: ";
		printPoint(X);
		std::cout << endl;
		std::cout << "Chieu dai: " << H << endl;
		std::cout << "Chieu rong: " << W << endl << endl;
	}
	void input() {
		std::cout << "Nhap hoanh do goc trai tren: ";
		std::cin >> X.X;
		std::cout << "Nhap tung do go trai tren: ";
		std::cin >> X.Y;
		std::cout << "Nhap chieu dai: ";
		std::cin >> H;
		std::cout << "Nhap chieu rong: ";
		std::cin >> W;
	}
};

