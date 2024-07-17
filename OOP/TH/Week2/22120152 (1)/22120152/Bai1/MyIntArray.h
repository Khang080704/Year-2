#pragma once
#ifndef array_H
#define array_H
#include <iostream>
using namespace std;
class MyIntArray
{
public:
	// Default Constructor
	MyIntArray();
	//Parameter Constructors: Using input items of array
	MyIntArray(int sz);
	// Destructor
	~MyIntArray();
	// Overloading [] operator to access elements in array
	int& operator[](int i);
	// Copy Constructor
	MyIntArray(MyIntArray& a);
	// Assignment Operator Overloading
	MyIntArray& operator=(const MyIntArray&);
	// xuat mang
	void print();
private:
	int* pArr;
	int size;
};
#endif
