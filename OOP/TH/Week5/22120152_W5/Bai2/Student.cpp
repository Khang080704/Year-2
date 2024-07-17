#include "Student.h"
Student::Student() {
	maxCourse = 5;
	currentCourse = 0;
}
void Student::inputName() {
	getline(cin, studentName);
}
void Student::showName() {
	std::cout << studentName << endl;
}
void Student::courseRecord(string name) {
	schedule.push_back(name);
	currentCourse++;
}
bool Student::operator==(const Student& student) {
	return this->getStudent() == student.getStudent();
}