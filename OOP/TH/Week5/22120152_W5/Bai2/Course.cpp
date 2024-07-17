#include "Course.h"
Course::Course() {
	maxStudent = 40;
	currentStudent = 0;
}
void Course::inputCourse() {
	getline(cin, courseName);
}
void Course::showCourse() {
	cout << courseName << endl;
}
void Course::studentRecord(string stuName) {
	roster.push_back(stuName);
	currentStudent++;
}
bool Course::operator==(const Course& course) {
	return this->getCourse() == course.getCourse();
}