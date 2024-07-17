#include "NVCongNhat.h"
const int PRICE = 300000;	
int NVCongNhat::getSalary() {
	return workDay * PRICE;
}
void NVCongNhat::outputInfor() {
	NhanVien::outputInfor();
	cout << "Loai: " << type << endl;
	cout << "Luong: " << getSalary() << endl;
	cout << endl;
}
void NVCongNhat::inputInfor() {
	NhanVien::inputInfor();
	cout << "Nhap so ngay di lam: ";
	cin >> workDay;
	cin.ignore();
	cout << endl;
}