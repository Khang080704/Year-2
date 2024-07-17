#include "Stack.h"
Stack::Stack(int capicity) {
	ptr = new int[capicity];
	this->capacity = capicity;
	this->size = 0;
}
Stack::~Stack() {
	delete[] ptr;
	size = 0;
	capacity = 0;
}
int Stack::pop() {
	int value = ptr[size - 1];
	size--;
	return value;
}
void Stack::push(const int& element) {
	ptr[size] = element;
	size++;
}