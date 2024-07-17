#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include<sstream>
using namespace std;
// Cau truc Diem
struct Point {
	double X;
	double Y;
};
double distance(Point A, Point B);
void printPoint(Point A);
// Lop doi tuong hinh ve tong quat 'Shape'
class Shape {
protected:
	string name;
public:
	
	// Constructors, Example: Shape(); ~Shape();
	Shape(string);
	Shape();
	/* Se cai dat lai trong tung lop dan xuat */

	virtual Shape* Clone() = 0;
	virtual bool IsSelected(Point p) = 0;
	// Tính diện tích
	virtual double CalArea() = 0;
	// other methods, Example: input(); print();
	virtual void print() = 0;
	virtual void input() = 0;
	string toString();
	string getName() const {
		return name;
	}
	~Shape() = default;
};


