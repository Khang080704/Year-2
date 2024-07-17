#include"Diem.h"
void NhapDiem(Diem* d) {
	std::cout << "Nhap hoanh do: ";
	std::cin >> d->x;
	cout << "Nhap tung do: ";
	cin >> d->y;
}
void XuatDiem(Diem d) {
	cout << "(" << d.x << "," << d.y << ")" << " ";
}
float khoangCach(Diem a, Diem b) {
	return sqrt((b.x - a.x) * (b.x - a.x)
		+ (b.y - a.y) * (b.y - a.y));
}