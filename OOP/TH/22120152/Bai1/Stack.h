#pragma once
class Stack
{
private:
	int* ptr; // array
	int capacity; // max size
	int size; // current size
public:
	// Constructor
	Stack(int capacity);
	// destructor
	~Stack();
	// Them phan tu vao stack, them vào cuoi
	void push(const int& element);
	//Lay phan tu ra khoi stack
	int pop();
};
