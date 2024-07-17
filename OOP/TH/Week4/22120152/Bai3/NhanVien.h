#pragma once
#include<iostream>
#include<string>
using namespace std;

struct Date {
	int day;
	int month;
	int year;
	void inputDate() {
		cout << "Nhap ngay sinh: ";
		cin >> day;
		cout << "Nhap thang sinh: ";
		cin >> month;
		cout << "Nhap nam sinh: ";
		cin >> year;
	}
	void outputDate() {
		cout << day << "/" << month << "/" << year << endl;
	}
};

class NhanVien
{
public:
	//Attributes
	string ID;
	string fullName;
	Date birthDay;
	string address;

	//Methods
	NhanVien();
	virtual void inputInfor();
	virtual void outputInfor();
	virtual int getSalary() = 0;


};

