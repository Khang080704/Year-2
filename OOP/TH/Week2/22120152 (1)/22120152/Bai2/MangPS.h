#pragma once
#include"PhanSo.h"
class MangPS
{
public:
	MangPS();
	MangPS(const MangPS& p);
	MangPS(int size);
	void input(int n);
	void output();
	PhanSo sumPS();
	void sort();
	~MangPS();
private:
	PhanSo* data;
	int size;
};

