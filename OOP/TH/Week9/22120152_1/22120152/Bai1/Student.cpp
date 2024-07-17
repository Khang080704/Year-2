#include "Student.h"

Student::Student()
{
	stdId = 0;
	stdGpa = 0;
	stdName = "";
}

Student::Student(int id, const string& name, double score) {
	stdId = id;
	stdName = name;
	stdGpa = score;
}

int Student::getId() const {
	return stdId;
}
string Student::getName() const {
	return stdName;
}
double Student::getGpa() const {
	return stdGpa;
}


Student::~Student()
{
}
