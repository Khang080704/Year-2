#pragma once
#include "Shape.h"
class Circle :public Shape
{
protected:
	Point C; //toạ độ tâm
	double R; //độ dài bán kính
public:
	// Constructors
	Circle();
	Circle(double radius) ;
	Circle(Point c, double radius);
	Circle(const Circle& c);
	// Overriding Shape class’s IsSelected method
	bool IsSelected(Point);
	Circle& operator=(const Circle&);
	// Overriding Shape class’s Clone method
	Shape* Clone() {
		Circle* p = new Circle;
		if (p == NULL) return NULL;
		p->C = C;
		p->R = R;
		return p;
	}
	//Tính diện tích 
	double CalArea();
	void print() {
		std::cout << getName() << endl;
		std::cout << "Toa do tam: ";
		printPoint(C);
		std::cout << endl;
		std::cout << "Ban kinh: " << R << endl << endl;
	}
	void input() {
		std::cout << "Nhap tung do: ";
		cin >> C.Y;
		std::cout << "Nhap hoanh do: ";
		std::cin >> C.X;
		std::cout << "Nhap ban kinh: ";
		std::cin >> R;
	}

};

