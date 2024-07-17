#include "SinhVien.h"
//Ghi vao file input
string input = "input.txt";
ofstream write(input, ios::app);

//Ghi vao file output
string output = "output.txt";
ofstream printFile(output, ios::app);

SinhVien::SinhVien(string name, string id, string birthDay
	, double midTerm, double finalTerm, double practice) {
	this->name = name;
	this->id = id;
	this->birthday = birthDay;
	this->midTerm = midTerm;
	this->finalTerm = finalTerm;
	this->practice = practice;
}
SinhVien::SinhVien(SinhVien& temp) {
	name = temp.name;
	id = temp.id;
	birthday = temp.birthday;
	practice = temp.practice;
	midTerm = temp.midTerm;
	finalTerm = temp.finalTerm;
}
SinhVien::SinhVien() {
	name = id = birthday = "";
	midTerm = practice = finalTerm = 0.0;
}
double SinhVien::average() {
	return practice * 0.25 + midTerm * 0.25 + finalTerm * 0.5;
}
void SinhVien::show() {
	cout <<"Thong tin: " << name << " - " << id << " - " << birthday << endl;
	cout << "Diem: " << practice << " " << midTerm << " " << finalTerm << endl;
	cout << "Diem trung binh: " << average() << endl;
}
void SinhVien::upDate() {
	write << endl;
	write << name << endl;
	write << id << endl;
	write << birthday << endl;
	write << practice << endl;
	write << midTerm << endl;
	write << finalTerm;
	write.close();
}

void SinhVien::showInFile() {

	printFile << name << " - " << id << endl;
	printFile << "Average: " << average() << endl;
	printFile.close();
}

void SinhVien::ranking() {
	if (average() > 8) {
		show();
		cout << endl;
		cout << "Xep loai: Gioi" << endl;
		cout << endl;
	}
	else {
		if (average() > 7) {
			show();
			cout << "Xep loai: Kha" << endl;
			cout << endl;
		}
		else {
			if (average() > 5) {
				show();
				cout << "Xep loai: Trung binh" << endl;
				cout << endl;
			}
			else{
				show();
				cout << "Xep loai: Yeu" << endl;
				cout << endl;
			}
		}
	}
}