#include "NhanVien.h"

NhanVien::NhanVien() {
	ID = "";
	fullName = "";
	birthDay.day = birthDay.month = birthDay.year = 0;
	address = "";
	gender = "";
}
NhanVien::NhanVien(string type) {
	this->type = type;
	ID = "";
	fullName = "";
	birthDay.day = birthDay.month = birthDay.year = 0;
	address = "";
	gender = "";
}
void NhanVien::inputInfor() {
	std::cout << "Nhap ten: ";
	getline(cin, fullName);
	std::cout << "Nhap ID: ";
	getline(cin, ID);
	if (ID.length() != 5) {
		throw 404;
	}
	
	std::cout << "Nhap dia chi: ";
	getline(cin, address);
	std::cout << "Nhap gioi tinh (Nam/Nu): ";
	getline(cin, gender);
	birthDay.inputDate();
	if (gender == "Nam" && (birthDay.getAge() < 18 || birthDay.getAge() > 60)) {
		throw out_of_range("Invalid age");
	}
	else {
		if (gender == "Nu" && (birthDay.getAge() < 18 || birthDay.getAge() > 55)) {
			throw "Invalid age";
		}
		else {
			throw invalid_argument("");
		}
	}
	
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
string NhanVien::getType() {
	return type;
}
NhanVien& NhanVien::operator=(const NhanVien& src) {
	this->fullName = src.fullName;
	this->birthDay = src.birthDay;
	this->address = src.address;
	this->ID = src.ID;
	this->type = src.type;
	this->gender = src.gender;
	return *this;
}