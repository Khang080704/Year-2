#pragma once
#include<iostream>
using namespace std;

class PhanSo
{
public:
	PhanSo();
	PhanSo(int, int);
	PhanSo(const PhanSo&);

	friend istream& operator>>(istream& input, PhanSo& a) {
		input >> a.tuSo >> a.mauSo;
		return input;
	}
	friend ostream& operator<<(ostream& output, PhanSo a) {
		output << a.tuSo << "/" << a.mauSo << endl;
		return output;
	}
	PhanSo& operator+(PhanSo a);
	PhanSo& operator-(PhanSo a);
	PhanSo& operator*(PhanSo a);
	PhanSo& operator/(PhanSo a);
	PhanSo& operator+=(PhanSo a);
	bool operator>(PhanSo a);
	bool operator<(PhanSo a);
	bool operator==(PhanSo a);
	bool operator>=(PhanSo a);
	bool operator<=(PhanSo a);
	
private:
	int tuSo;
	int mauSo;
};

