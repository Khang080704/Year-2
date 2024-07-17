#include "Registrar.h"
Registrar::Registrar(vector<Student> student, vector<Course> course) {
	StudentData = student;
	CourseData = course;
}
void Registrar::Regist_Course(Student s, Course c) {
	for (int i = 0; i < StudentData.size();i++) {
		if (StudentData[i].getStudent() == s.getStudent()) {
			for (int j = 0; j < CourseData.size();j++) {
				if (CourseData[j].getCourse() == c.getCourse()) {
					if (StudentData[i].getMaxCourse() == StudentData[i].getCurrentCourse()) {
						cout << StudentData[i].getStudent() << " has full of courses!" << endl;
						return;
					}
					else {
						if (CourseData[j].getMaxStudent() == CourseData[j].getCurrentStudent()) {
							cout << CourseData[j].getCourse() << " has full students!" << endl;
							return;
						}
						else {
							StudentData[i].courseRecord(CourseData[j].getCourse());
							CourseData[j].studentRecord(StudentData[i].getStudent());
							return;
						}
					}
				}
			}
			cout << "Khong ton tai khoa hoc!" << endl;
			return;
		}
	}	
}

void Registrar::showStudentList() {
	std::cout << "Danh sach sinh vien: " << endl;
	for (int i = 0; i < StudentData.size(); i++) {
		StudentData[i].showName();
	}
	cout << endl;
}
void Registrar::showCourseList() {
	cout << "Danh sach khoa hoc: " << endl;
	for (Course j : CourseData) {
		j.showCourse();
	}
	cout << endl;
}
void Registrar::showStudentSchedule() {
	for (Student i : StudentData) {
		i.showName();
		i.showSchedule();
	}
}
void Registrar::showCoursMember() {
	for (Course i : CourseData) {
		i.showCourse();
		i.showMembers();
		cout << endl;
	}
}