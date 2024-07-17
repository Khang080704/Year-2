#include "darray.h"

darray::darray()
{
	sz = space = 0;
	elem = new int[100];
}
darray::darray(int s) {
	space = s;
	sz = 0;
	elem = new int[space];
}
darray::darray(const darray& d) {
	this->sz = d.sz;
	this->space = d.space;
	elem = new int[this->sz];
	for (int i = 0; i < this->sz; i++) {
		elem[i] = d.elem[i];
	}
}
darray& darray::operator=(const darray& d) {
	this->sz = d.sz;
	this->space = d.space;
	elem = new int[this->sz];
	for (int i = 0; i < this->sz; i++) {
		elem[i] = d.elem[i];
	}
	return *this;

}
int darray::size() const {
	return sz;
}
int darray::capacity() const {
	return sz + space;
}
int& darray::operator[](int i) {
	return elem[i];
}
void darray::resize(int newsize) {
	if (newsize <= sz) {
		sz = newsize;
	}
	else {
		
		for (int i = sz; i < newsize; i++) {
			elem[i] = 0;
		}
		sz = newsize;
		space = newsize;
	}
}
void darray::reserve(int newalloc) {
	this->space = newalloc;
	sz = 0;
	elem = new int[space];
}
void darray::push_back(int d) {
	elem[this->sz] = d;
	this->sz++;
}
void darray::print() {
	if (sz >= space) {
		for (int i = 0; i < space; i++) {
			cout << elem[i] << " ";
		}
	}
	else {
		for (int i = 0; i < sz; i++) {
			cout << elem[i] << " ";
		}
	}
	
}
darray::~darray()
{
	delete[] elem;
}
