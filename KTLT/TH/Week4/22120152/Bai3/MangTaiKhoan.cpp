#include"MangTaiKhoan.h"
void nhapMang(TaiKhoan*& x, int n) {
	for (int i = 0; i < n; i++) {
		Nhap(x[i]);
	}
}
void xuatMang(TaiKhoan* x, int n) {
	cout << "Danh sach tai khoan: " << endl;
	for (int i = 0; i < n; i++) {
		xuat(x[i]);
	}
}