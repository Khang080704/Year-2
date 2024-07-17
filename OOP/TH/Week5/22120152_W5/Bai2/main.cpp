#include"Student.h"
#include"Course.h"



int main()
{
	vector<Student> studentData;
	vector<Course> courseData;
	cout << "Nhap so luong sinh vien: ";
	int studentNum = 0; cin >> studentNum;
	cin.ignore();
	
	for (int i = 0; i < studentNum; i++) {
		Student temp;
		temp.inputName();
		studentData.push_back(temp);
	}

	cout << "Nhap so luong khoa hoc: ";
	int courseNum = 0; cin >> courseNum;
	cin.ignore();

	for (int i = 0; i < courseNum; i++) {
		Course temp;
		temp.inputCourse();
		courseData.push_back(temp);
	}

	
	

}