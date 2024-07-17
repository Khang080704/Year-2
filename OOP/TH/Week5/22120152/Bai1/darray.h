/* Dinh nghia lop vector */
#pragma
#include<iostream>
#include<vector>
using namespace std;
class darray {
	int sz; // the size, number of elements
	int* elem; // a pointer to the elements
	int space; // size + free space
public:
	// Constructors
	// default constructor
	darray();
	// parameter constructor
	darray(int s);
	// copy constructor
	darray(const darray&);
	// copy assignment
	darray& operator=(const darray&);
	// destructor
	~darray();
	// get function
	int size() const;
	int capacity() const;
	// access: return reference
	int& operator[](int n);
	// Mở rộng bộ nhớ => Gọi hàm reserve(newsize)
	// và khởi tạo các phần tử mới
	void resize(int newsize);
	// Hàm dùng để thêm không gian (space) cho các phần tử mới
	// Tương tự hàm realloc() trong C
	void reserve(int newalloc);
	// Ham them 1 phan tu vao mang dong
	void push_back(int d);
	// Other functions
	void print();
};
