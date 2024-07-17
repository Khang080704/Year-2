#pragma once
#include"DonThuc.h"
#include<algorithm>
class DaThuc
{
private:
	DonThuc* data;
	int operandNumber;
	void erase(int index);
public:
	DaThuc(int number);
	DaThuc(const DaThuc&);
	~DaThuc();
	void input();
	void output();
	int calculate_value(int value);
	void stadardize();
	void sortByDegree();
	int highestDegree();
	DonThuc highestOperand();
	DaThuc operator+(const DaThuc&);
	DaThuc operator-(const DaThuc&);
	DaThuc operator*(const DaThuc&);
	DonThuc& operator[](int index);
};

