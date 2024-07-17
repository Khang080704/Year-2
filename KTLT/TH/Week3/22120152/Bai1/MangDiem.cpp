#include"MangDiem.h"
Diem* NhapMangDiem(int& n) {
	cout << "Nhap n: ";
	cin >> n;

	Diem* a = new Diem[n];
	for (int i = 0; i < n; i++) {
		NhapDiem(&a[i]);
	}
	return a;
}
void xuatMangDiem(Diem* a, int n) {
	for (int i = 0; i < n; i++) {
		XuatDiem(a[i]);
	}
}
Diem TimXaNhat(Diem* a, int n, Diem A) {
	Diem max = a[0];
	float kc = khoangCach(a[0], A);

	for (int i = 0; i < n; i++) {
		//Tinh khoang cach tu a[i] den A
		float kc2 = khoangCach(a[i], A);

		if (kc2 > kc) {
			max = a[i];
			kc = kc2;
		}
	}
	return max;
}
void LietKeToaDoDuong(Diem* a, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i].x > 0 && a[i].y > 0) {
			XuatDiem(a[i]);
		}
	}
}
void SapTangTheoKhoangCach(Diem* a, int n) {
	Diem gocToaDo;
	gocToaDo.x = 0;
	gocToaDo.y = 0;

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (khoangCach(a[i], gocToaDo) > khoangCach(a[j], gocToaDo)) {
				Diem temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	xuatMangDiem(a, n);
}