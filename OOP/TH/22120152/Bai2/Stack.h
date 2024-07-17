#ifndef STACK_H
#define STACK_H
#include "list.h"
// Dinh nghia lop Stack su dung doi tuong list

class Stack {
private:
	List list;
	/*int capacity;
	int size;*/
public:
	void push(const string& val);
	void pop();
	string top();
	int size();
};
#endif

