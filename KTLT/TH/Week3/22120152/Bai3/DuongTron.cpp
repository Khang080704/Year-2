#include"DuongTron.h"
DuongTron* TaoDuongTron(float xV, float yV, float rV) {
	DuongTron* dt = new DuongTron;
	dt->tam = new Diem;
	dt->tam->x = xV;
	dt->tam->y = yV;
	dt->banKinh = rV;
	return dt;
}
void XoaDuongTron(DuongTron* p) {
	delete p;
}
void PrintDuongTron(DuongTron* p) {
	cout << "[(" << p->tam->x << "," << p->tam->y << "), " << p->banKinh << "]";
}
float tinhChuVi(DuongTron* p) {
	return p->banKinh * 2 * PI;
}
DuongTron* ChuViLonNhat(DuongTron** l, int n) {
	float maxChuVi = tinhChuVi(l[0]);
	DuongTron* max = l[0];
	for (int i = 1; i < n; i++) {
		if (maxChuVi < tinhChuVi(l[i])) {
			maxChuVi = tinhChuVi(l[i]);
			max = l[i];
		}
	}
	return max;
}
float tinhDienTich(DuongTron* p) {
	return p->banKinh * p->banKinh * PI;
}
float TongDienTich(DuongTron** l, int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += tinhDienTich(l[i]);
	}
	return sum;
}
int XuatCacDuongTronDTLonHonTB(DuongTron** l, int n) {
	float average = TongDienTich(l, n) / n;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (tinhDienTich(l[i]) > average) {
			PrintDuongTron(l[i]);
			cout << endl;
			count++;
		}
	}
	return count;
}
void XuatDuongTronChuViGiam(DuongTron** l, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j =  i + 1; j < n; j++) {
			if (tinhChuVi(l[i]) < tinhChuVi(l[j])) {
				DuongTron* temp = l[i];
				l[i] = l[j];
				l[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		PrintDuongTron(l[i]);
		cout << " Voi P = " << tinhChuVi(l[i]) << endl;
	}
}
void XoaDsDuongTron(DuongTron** l, int n) {
	delete[] l;
}