#include"NVCongNhat.h"
#include"NVSanXuat.h"
#include"CongTy.h"
#include<string>

void inputEmployee(CongTy& c, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap loai nhan vien (SX/CN): ";
		string type; cin >> type;
		cin.ignore();
		if (type != "SX" && type != "CN") {
			cout << "Khong hop le! " << endl;
			i--;
		}
		else {
			c.input(type);
		}
		
	}
}

int main() {
	CongTy company(100);
	//Thong bao
	cout << "Chuong trinh quan li nhan vien: " << endl;
	cout << "1. Nhap thong tin nhan vien: " << endl;
	cout << "2. Xuat thong tin nhan vien: " << endl;
	cout << "3. Tinh tong luong nhan vien: " << endl;
	cout << "4. Tinh luong trung binh cua cong ty: " << endl;
	cout << "5. Tim kiem nhan vien theo ma: " << endl;
	cout << "6. Tim kiem nhan vien theo ten: " << endl;
	cout << "7. Dem nhan vien theo thang sinh: " << endl;
	cout << "8. Ket thuc chuong trinh: " << endl;
	
	int userChoose = 0;
	do
	{
		cout << "Vui long chon chuc nang: ";
		cin >> userChoose;
		switch (userChoose)
		{
		case 1: {
			cout << "Nhap so luong nhan vien: ";
			int n; cin >> n;
			
			inputEmployee(company, n);
			cout << "Da cap nhat danh sach nhan vien!" << endl;
			break;
		}
		case 2: {
			cout << "Danh sach nhan vien la: " << endl;
			company.output();
			break;
		}
		case 3: {
			int sumSalary = company.getSumOfSalary();
			cout << "Tong luong la: " << sumSalary << endl;
			break;
		}
		case 4: {
			float averageSalary = company.averageSalary();
			cout << "Luong trung binh la: " << averageSalary << endl;
			break;
		}
		case 5: {
			string ID = "";
			cout << "Nhap vao ID can tim kiem: "; cin >> ID;
			company.findWithID(ID);
			break;
		}
		case 6: {
			string name = "";
			cout << "Nhap ten can tim kiem: "; cin >> name;
			company.findWithName(name);
			break;
		}
		case 7: {
			int month = 0;
			cout << "Nhap vao thang can tim: "; cin >> month;
			int number = company.countByMonth(month);
			cout << "Co " << number << " nhan vien sinh thang " << month << endl;
			break;
		}
		default:
			cout << "Chuong trinh ket thuc" << endl;
			break;
		}
	} while (userChoose != 8);
	
	
}