#include"MangDiem.h"
int main()
{
	Diem* a;
	int n = 0;
	a = NhapMangDiem(n);
	xuatMangDiem(a, n);
	cout << endl;
	Diem b;
	cout << "Nhap diem B: ";
	NhapDiem(&b);
	Diem maxDistance = TimXaNhat(a, n, b);
	cout << "Diem xa b nhat la: ";
	XuatDiem(maxDistance);
	cout << endl;
	cout << "Nhung diem co toa do duong la: " << endl;
	LietKeToaDoDuong(a, n);
	cout << endl;
	cout << "Mang diem sau khi sap xep tang dan theo khoang cach toi goc toa do: " << endl;
	SapTangTheoKhoangCach(a, n);
}