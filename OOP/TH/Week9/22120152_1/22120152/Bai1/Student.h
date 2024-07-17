#ifndef STUDEN_H
#define STUDEN_H
#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <string>
using namespace std;
class Student
{
private:
	int stdId;
	string stdName;
	double stdGpa;
public:
	Student(int, const string&, double);
	Student();
	~Student();
	int getId() const;
	string getName() const;
	double getGpa() const;
	friend istream& operator>>(istream& input, Student& src) {
		std::cout << "Nhap ten: ";
		getline(input, src.stdName);
		std::cout << "Nhap ID: ";
		input >> src.stdId;
		std::cout << "Nhap GPA: ";
		input >> src.stdGpa;
		input.ignore();
		return input;
	}
	friend ostream& operator<<(ostream& out, const Student& src) {
		out << src.stdName << " - " << src.stdId << " - " << src.stdGpa << endl;
		return out;
	}
};
#endif

