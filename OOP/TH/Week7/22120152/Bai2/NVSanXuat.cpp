#include "NVSanXuat.h"
const int PRICE = 20000;
int NVSanXuat::getSalary() {
	return productNumber * PRICE;
}
void NVSanXuat::outputInfor() {
	NhanVien::outputInfor();
	cout << "Loai: " << type << endl;
	cout << "Luong: " << getSalary() << endl;
	cout << endl;
}
void NVSanXuat::inputInfor() {
	NhanVien::inputInfor();
	std::cout << "Nhap so san pham lam ra: ";
	cin >> productNumber;
	cin.ignore();
	cout << endl;
}