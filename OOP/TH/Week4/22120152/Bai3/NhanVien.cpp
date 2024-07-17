#include "NhanVien.h"
NhanVien::NhanVien() {
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