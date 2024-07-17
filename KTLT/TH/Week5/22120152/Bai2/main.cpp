#include"MangTaiKhoan.h"

void show() {
	cout << "1. Sap xep theo tuoi" << endl;
	cout << "2. Sap xep theo ten dang nhap" << endl;
	cout << "3. Sap xep theo ho ten" << endl;
}
int main()
{
	cout << "Nhap so luong tai khoan: ";
	int n; cin >> n;
	cin.ignore();
	TaiKhoan* data = new TaiKhoan[n];
	nhapMang(data, n);
	cout << "Chon chuc nang sap xep: " << endl;
	cout << "1. Tang dan" << endl;
	cout << "2. Giam dan" << endl;
	int userSortChoose = 0; cin >> userSortChoose;
	switch (userSortChoose)
	{
	case 1: {
		show();
		int method = 0;
		cin >> method;
		switch (method)
		{
		case 1: {
			sapXepTheoTuoi(data, n, soSanhNhoHon); 
			break;
		}
		case 2: {
			sapXepTheoTenDangNhap(data, n, soSanhTheoChuoiNhoHon);
			break;
		}
		case 3: {
			sapXepTheoHoTen(data, n, soSanhTheoChuoiNhoHon);
			break;
		}

		default:
			break;
		}
		break;
	}
	case 2: {
		show();
		int method = 0;
		cin >> method;
		switch (method)
		{
		case 1: {
			sapXepTheoTuoi(data, n, soSanhLonHon);
			break;
		}
		case 2: {
			sapXepTheoTenDangNhap(data, n, soSanhTheoChuoiLonHon);
			break;
		}
		case 3: {
			sapXepTheoHoTen(data, n, soSanhTheoChuoiLonHon);
			break;
		}
			
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
	cout << "Danh sach tai khoan sau khi sap xep: " << endl;
	xuatMang(data, n);
	delete[] data;
	

}