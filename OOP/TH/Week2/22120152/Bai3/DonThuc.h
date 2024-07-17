#pragma once
#include<iostream>
using namespace std;

class DonThuc
{
private:
	int expoment;
	int coefficient;
public:
	DonThuc();
	//Nhap xuat don thuc
	friend istream& operator >>(istream& input, DonThuc& a);
	friend ostream& operator <<(ostream& output, DonThuc a);
	void display();
	int getDegree();
	//Tinh gia tri
	int Calculate_value(int value);
	//Cong
	DonThuc& operator +(DonThuc x);
	DonThuc& operator -(DonThuc x);
	DonThuc& operator *(DonThuc x);
	DonThuc& operator /(DonThuc x);
	DonThuc& operator =(const DonThuc& x);
	bool operator == (const DonThuc& x);
};

