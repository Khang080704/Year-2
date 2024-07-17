#include<iostream>
using namespace std;

int demSoLuongChuSo(int n) {
	if (n >= 0 && n <= 9) {
		return 1;
	}
	return 1 + demSoLuongChuSo(n / 10);
}

int TinhTongChuSo(int n) {
	if (n >= 0 && n <= 9) {
		return n;
	}
	return n % 10 + TinhTongChuSo(n / 10);
}

int tinhTichChuSoLe(int n) {
	if (n >= 0 && n <= 9 && n % 2 == 1) {
		return n;
	}
	else {
		if (n >= 0 && n <= 9 && n % 2 == 0) {
			return 0;
		}
		if ((n % 10) % 2 == 1) {
			return n % 10 * tinhTichChuSoLe(n / 10);
		}
		else {
			return tinhTichChuSoLe(n / 10);
		}
	}
}

bool kiemTraToanLe(int n) {
	if (n >= 0 && n <= 9 && n % 2 == 1) {
		return true;
	}
	else {
		if ((n % 10) % 2 == 0) {
			return false;
		}
		else {
			return kiemTraToanLe(n / 10);
		}
	}
}

bool kiemTraToanChan(int n) {
	if (n >= 0 && n <= 9 && n % 2 == 0) {
		return true;
	}
	else {
		if ((n % 10) % 2 == 1) {
			return false;
		}
		else {
			return kiemTraToanChan(n / 10);
		}
	}
}

int main()
{
	cout << "Nhap vao so nguyen duong n:";
	int n; cin >> n;
	cout << "So luong chu so cua " << n << " la: " << demSoLuongChuSo(n) << endl;
	cout << "Tong cac chu cua " << n << " la: " << TinhTongChuSo(n) << endl;
	cout << "Tich cac chu so le cua " << n << " la: " << tinhTichChuSoLe(n) << endl;
	if (kiemTraToanLe(n)) {
		cout << n << " la so toan le" << endl;
	}
	else {
		cout << n << " khong la so toan le" << endl;
	}
	if (kiemTraToanChan(n)) {
		cout << n << " la so toan chan" << endl;
	}
	else {
		cout << n << " khong la so toan chan" << endl;
	}
}