#include "Registrar.h"
Registrar::Registrar(vector<Student> student, vector<Course> course) {
	StudentData = student;
	CourseData = course;
}
void Registrar::Regist_Course(Student s, Course c) {
	for (Student i : StudentData) {
		if (i == s) {
			for (Course j : CourseData) {
				if (j == c) {
					if (i.getMaxCourse() == 5) {
						cout << i.getStudent() << " has full of courses!" << endl;
						return;
					}
					else {
						if (j.getMaxStudent() == 40) {
							cout << j.getCourse() << " has full students!" << endl;
							return;
						}
						else {
							i.courseRecord(j.getCourse());
							j.studentRecord(i.getStudent());
						}
					}
				}
			}
		}
	}	
}

void Registrar::showStudentList() {
	for (int i = 0; i < StudentData.size(); i++) {
		StudentData[i].showName();
	}
}
void Registrar::showCourseList() {
	for (Course j : CourseData) {
		j.showCourse();
	}
}