#include "NhanVien.h"
NhanVien::NhanVien() {
	ID = "";
	fullName = "";
	birthDay.day = birthDay.month = birthDay.year = 0;
	address = "";
}
NhanVien::NhanVien(string type) {
	this->type = type;
	ID = "";
	fullName = "";
	birthDay.day = birthDay.month = birthDay.year = 0;
	address = "";
}
void NhanVien::inputInfor() {
	std::cout << "Nhap ten: ";
	getline(cin, fullName);
	std::cout << "Nhap ID: ";
	getline(cin, ID);
	std::cout << "Nhap dia chi: ";
	getline(cin, address);
	birthDay.inputDate();
}
void NhanVien::outputInfor() {
	cout << "Ho ten: " << fullName << endl;
	cout << "ID: " << ID << endl;
	cout << "Dia chi: " << address << endl;
	cout << "Ngay thang nam sinh: ";
	birthDay.outputDate();
}
string NhanVien::getID() const {
	return ID;
}
string NhanVien::getName() const {
	return fullName;
}
Date NhanVien::getBirthDay() const {
	return birthDay;
}