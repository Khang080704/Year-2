#pragma once
#include "SinhVien.h"


class QLSinhVien
{
public:
	QLSinhVien();
	~QLSinhVien();
	void add(SinhVien a);
	int size();
	void display();
	void findUnderAverage();
	bool isEmpty();
	void xepLoai();
private:
	SinhVien* data;
	int number;
};

