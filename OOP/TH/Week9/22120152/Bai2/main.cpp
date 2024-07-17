#include"NVCongNhat.h"
#include"NVSanXuat.h"
#include"CongTy.h"
#include<string>


int main() {
	CongTy company(100);
	string input = "input.bin";
	string output = "ouput.bin";
	//Thong bao
	cout << "Chuong trinh quan li nhan vien: " << endl;
	cout << "1. Nhap thong tin nhan vien: " << endl;
	cout << "2. Xuat thong tin nhan vien: " << endl;
	cout << "3. Ghi danh sach sinh vien vao tap tin nhi phan: " << endl;
	cout << "4. Doc danh sach tu tap tin va xuat ra man hinh: " << endl;
	cout << "5. Tinh tong luong cua tung loai nhan vien: " << endl;
	cout << "6. Tim nhan vien co luong cao nhat: " << endl;
	cout << "7. Ghi tat ca nhan vien co luong lon hon luong trung binh"
		 << " vao file nhi phan: " << endl;
	cout << "8. Xuat file nhi phan co thong tin luong: " << endl;
	cout << "9. Sap xep tang dan theo ma so nhan vien: " << endl;
	cout << "0. Ket thuc chuong trinh " << endl;

	int userChoose = 0;
	do
	{
		cout << "Vui long chon chuc nang: ";
		cin >> userChoose;
		cin.ignore();
		switch (userChoose)
		{
		case 1: {
			try {
				company.input();
			}
			catch (int a) {
				cout << "ID khong hop le " << endl;
			}
			catch (out_of_range& e) {
				cout << e.what() << endl;
			}
			catch (const char* a) {
				cout << a << endl;
			}
			catch (...) {
				cout << "Error" << endl;
			}
			cout << "Da cap nhat danh sach nhan vien!" << endl;
			break;
		}
		case 2: {
			cout << "Danh sach nhan vien la: " << endl;
			company.output();
			break;
		}
		case 3: {
			company.WriteToFile(input);
			cout << "Da ghi danh sach nhan vien vao file" << endl;
			break;
		}
		case 4: {

			company.ReadFromFile(input);
			break;
		}
		case 5: {
			cout << "Tong luong cua nhan vien cong nhat: " << company.NVCNSalary() << endl;
			cout << "Tong luong cua nhan vien san xuat: " << company.NVSXSalary() << endl;
			break;
		}
		case 6: {
			NhanVien* max = company.findMaxSalary();
			max->outputInfor();
			break;
		}
		case 7: {
			company.writeSalaryToFile(output);
			cout << "Da ghi danh sach nhan vien vao file " << output << endl;
			break;
		}
		case 8: {
			company.readSalaryFromFile(output);
			break;
		}
		case 9: {
			company.sortByID();
			cout << "Danh sach nhan vien da sap xep: " << endl;
			company.output();
			break;
		}
		default:
			cout << "Chuong trinh ket thuc" << endl;
			break;
		}
	} while (userChoose != 0);
	


}