#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Schedule.h"
using namespace std;
class Student
{
public:
	Student();// show course student attempt
	void inputName();
	void showName();
	string getStudent() const {
		return studentName;
	}
	int getMaxCourse() const {
		return maxCourse;
	}
	void courseRecord(string courseName); // add course into student schedule
	bool operator == (const Student& student);

private:
	string studentName;
	vector<string> schedule;
	int maxCourse;
	int currentCourse;
};

