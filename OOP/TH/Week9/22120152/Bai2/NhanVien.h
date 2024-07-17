#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<exception>
using namespace std;
const int CURRENT_YEAR = 2024;

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
	int getAge() const {
		return CURRENT_YEAR - year;
	}
	Date& operator=(const Date& src) {
		this->day = src.day;
		this->month = src.month;
		this->year = src.year;
		return *this;
	}
	
};

class NhanVien : public exception
{
protected:
	//Attributes
	string ID;
	string fullName;
	Date birthDay;
	string address;
	string type; // Type of employee
	string gender;
public:
	//Methods
	NhanVien();
	NhanVien(string type);
	virtual void inputInfor();
	virtual void outputInfor();
	virtual int getSalary() = 0;
	string getID() const;
	string getName() const;
	Date getBirthDay() const;

	string getType();
	NhanVien& operator=(const NhanVien&);

	
};

