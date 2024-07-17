#pragma once
#include"Student.h"
#include"Course.h"
class Registrar
{
public:
	Registrar(vector<Student>, vector<Course>);
	void Regist_Course(Student, Course);// regist a course for student
	void showStudentList();
	void showCourseList();
	void showStudentSchedule();
	void showCoursMember();
private:
	vector<Student> StudentData;
	vector<Course> CourseData;

};

