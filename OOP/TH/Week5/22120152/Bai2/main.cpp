#include"Student.h"
#include"Course.h"
#include"Registrar.h"
#include<vector>
#include<sstream>

vector<string> splitCours(string courseList) {
	vector<string> result;
	stringstream ss(courseList);
	string buffer;
	while (ss >> buffer) {
		result.push_back(buffer);
	}
	return result;
}

int main()
{
	vector<Student> studentData;
	vector<Course> courseData;
	cout << "Nhap so luong sinh vien: ";
	int studentNum = 0; cin >> studentNum;
	cin.ignore();
	
	for (int i = 0; i < studentNum; i++) {
		cout << "Nhap ten sinh vien " << i + 1 << ": ";
		Student temp;
		temp.inputName();
		studentData.push_back(temp);
	}

	cout << "Nhap so luong khoa hoc: ";
	int courseNum = 0; cin >> courseNum;
	cin.ignore();

	for (int i = 0; i < courseNum; i++) {
		cout << "Nhap ten khoa hoc: " << i + 1 << ": ";
		Course temp;
		temp.inputCourse();
		courseData.push_back(temp);
	}

	Registrar data(studentData, courseData);
	data.showCourseList();
	data.showStudentList();

	cout << "Nhap ten sinh vien thuc hien dang ki khoa hoc: ";
	Student temp;
	temp.inputName();
	cout << "Nhap ten cac khoa hoc ma sinh vien nay dang ki( cach nhau bang khoang trang) " << endl;
	cout << "VD: oop ktlt dsa: ";
	string courseList = "";
	getline(cin, courseList);
	vector<string> courseRegist = splitCours(courseList);
	for (string i : courseRegist) {
		Course c(i);
		data.Regist_Course(temp, c);
	}
	cout << "Danh sach khoa hoc cac sinh vien da dang ki la: " << endl;
	data.showStudentSchedule();
	cout << "Danh sach thanh vien trong cac khoa hoc: " << endl;
	data.showCoursMember();

	
	

}