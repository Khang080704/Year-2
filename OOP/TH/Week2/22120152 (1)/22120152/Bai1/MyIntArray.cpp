#include "MyIntArray.h"


MyIntArray::MyIntArray()
{
	pArr = NULL;
	size = 0;
}
MyIntArray::MyIntArray(int sz) {
	pArr = new int[sz];
	size = sz;
}
int& MyIntArray::operator[](int i) {
	return pArr[i];
}
MyIntArray::MyIntArray(MyIntArray& a) {
	this->pArr = new int[a.size];
	this->size = a.size;
	for (int i = 0; i < size; i++) {
		this->pArr[i] = a[i];
	}
}
void MyIntArray::print() {
	for (int i = 0; i < size; i++) {
		std::cout << pArr[i] << " ";
	}
}

MyIntArray::~MyIntArray()
{
	delete[] pArr;
	size = 0;
}
