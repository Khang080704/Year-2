#pragma once
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include<fstream>
class ComplexShape 
{
protected:
	// Các hình vẽ thành phần: Circle, rectangle, ...
	int sz; //Number of shapes
	vector<Shape*> Children; //Array of <Shape*>
public:
	// Constructors
	ComplexShape(int size) {
		sz = size;
	}
	ComplexShape() = default;
	// Overriding Shape class’s IsSelected method
	bool IsSelected(Point);
	void addShape(Shape* shape);
	void input();
	void output();

	//Tính tổng diện tích các đường tròn
	double SumOfCircleArea();
	//Tính tổng diện tích các hình chữ nhật
	double SumOfRectangleArea();
	// Tìm đường tròn có diện tích lớn nhất
	Shape* findMaxCircleArea();
	//Calculate sum of area
	double sumArea();
	//file
	void writeToFile(string);
	void ReadFromFile(string);
	~ComplexShape()
	{
		for (auto shape : Children) {
			delete shape;
		}
	}

};

