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
void lietKeTheoTen(TaiKhoan* a, int n, char ten[]) {
	for (int i = 0; i < n; i++)
	{
		char s[51];
		strcpy_s(s, a[i].hoTen);
		char* p = strstr(s, ten);
		if (p != NULL) {
			xuat(a[i]);
		}
	}
}
int themTaiKhoan(TaiKhoan* a, int& n, TaiKhoan tk) {
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		char s[51];
		strcpy_s(s, a[i].tenDangNhap);
		char* p = strstr(s, tk.tenDangNhap);
		if (p != NULL) {
			xuat(a[i]);
			dem++;
		}
	}
	if (dem == 0) {
		a[n] = tk;
		n++;
	}
	return 1;
}
void xoaTaiKhoan(TaiKhoan* a, int& n, char tenDangNhap[]) {
	for (int i = 0; i < n; i++) {
		char s[31];
		strcpy_s(s, a[i].tenDangNhap);
		char* p = strstr(s, tenDangNhap);
		if (p != NULL) {
			for (int j = i; i < n; j++) {
				a[j] = a[j + 1];
			}
			n--;
		}
	}
}
int soSanhNhoHon(int a, int b) {
	return a < b;
}
int soSanhLonHon(int a, int b) {
	return a > b;
}
int soSanhTheoChuoiLonHon(char a[], char b[]) {
	if (strcmp(a, b) > 0) {
		return 1;
	}
	return 0;
}
int soSanhTheoChuoiNhoHon(char a[], char b[]) {
	return strcmp(a, b) < 0; // a < b
}
void sapXepTheoTuoi(TaiKhoan*& a, int n, int(*soSanh)(int, int)) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if(soSanh(tinhTuoi(a[i]),tinhTuoi(a[j])) == 0){
				TaiKhoan temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void sapXepTheoHoTen(TaiKhoan*& a, int n, int(*soSanh)(char[], char[])) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (soSanh(a[i].hoTen,a[j].hoTen) == 0) {
				TaiKhoan temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void sapXepTheoTenDangNhap(TaiKhoan*& a, int n, int(*soSanh)(char[], char[])) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (soSanh(a[i].tenDangNhap, a[j].tenDangNhap) == 0) {
				TaiKhoan temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}