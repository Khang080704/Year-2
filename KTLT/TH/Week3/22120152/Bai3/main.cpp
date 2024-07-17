#include"DuongTron.h"

int main() {
	srand(4003);
	int n = 5 + rand() % 20;
	DuongTron** listDT = new DuongTron * [n * sizeof(DuongTron)];
	if (listDT == NULL)
	{
		return 0;
	}
	float xV, yV, rV;
	for (int i = 0; i < n; ++i)
	{
		xV = (rand() % 1000) * 1.0f / 50;
		yV = (rand() % 1000) * 1.0f / 50;
		rV = (rand() % 1000 + 1) * 1.0f / 50;
		listDT[i] = TaoDuongTron(xV, yV, rV);
	}

	//Xuat duong tron co chu vi lon nhat
	cout << "Duong tron co chu vi lon nhat: ";
	DuongTron* pDTPMax = ChuViLonNhat(listDT, n);
	PrintDuongTron(pDTPMax);
	cout << endl;

	//Tong dien tich duong tron
	cout << "Tong dien tich: " << TongDienTich(listDT, n) << endl;

	//Xuat cac duong tron co dien tich lon hon dien tich trung binh
	cout << "Cac duong tron co dien tich lon hon TB:\n";
	int dem = XuatCacDuongTronDTLonHonTB(listDT, n);
	cout << "So luong: " << dem << endl;

	//Xuat ds duong tron giam dan theo chu vi
	cout << "Danh sach duong tron giam dan theo chu vi: " << endl;
	XuatDuongTronChuViGiam(listDT, n);

	//Thu hoi bo nho
	XoaDsDuongTron(listDT, n);
}