#include"MangTaiKhoan.h"
int main()
{
	
	cout << "Nhap so luong tai khoan: ";
	int n; cin >> n;
	cin.ignore();
	TaiKhoan* data = new TaiKhoan[n];
	nhapMang(data, n);
	xuatMang(data, n);
	delete[] data;
}