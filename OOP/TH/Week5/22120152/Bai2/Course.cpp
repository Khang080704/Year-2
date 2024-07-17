#include "Course.h"
Course::Course() {
	maxStudent = 40;
	currentStudent = 0;
}
Course::Course(string name) {
	courseName = name;
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
void Course::showMembers() {
	for (string i : roster) {
		cout << i << " ";
	}
	cout << endl;
}