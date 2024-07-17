#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Course //include many subjects
{
public:
	Course();
	void inputCourse();
	void showCourse();
	string getCourse() const {
		return courseName;
	}
	int getMaxStudent() const {
		return maxStudent;
	}
	void studentRecord(string); //add student's name into course
	bool operator ==(const Course& course);
private:
	string courseName;
	vector<string> roster;
	int maxStudent; // max number of student a course can has
	int currentStudent;
};

