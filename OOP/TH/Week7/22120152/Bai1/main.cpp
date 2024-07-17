#include"ComplexShape.h"
int main() {
	ComplexShape data(100);
	string input = "shape.dat";
	cout << "Chuong trinh quan li hinh ve: " << endl;
	cout << "1. Nhap thong tin hinh: " << endl;
	cout << "2. Xuat thong tin hinh: " << endl;
	cout << "3. Tinh tong dien tich cua tat ca hinh: " << endl;
	cout << "4. Tinh tong dien tich hinh tron: " << endl;
	cout << "5. Tinh tong dien tich hinh chu nhat: " << endl;
	cout << "6. Tim duong tron co dien tich lon nhat: " << endl;
	cout << "7. Ghi thong tin vao file: " << endl;
	cout << "8. Doc thong tin tu file: " << endl;
	cout << "0. ket thuc" << endl;
	
	int userChoose = 0;
	do
	{
		cout << "Vui long chon chuc nang: ";
		cin >> userChoose;
		cin.ignore();
		switch (userChoose)
		{
		case 1: {

			data.input();
			cout << "Da cap nhat danh sach hinh ve!" << endl;
			break;
		}
		case 2: {
			cout << "Danh sach hinh ve la: " << endl;
			data.output();
			break;
		}
		case 3: {
			double sumArea = data.sumArea();
			cout << "Tong dien tich cac hinh la: " << sumArea << endl;
			break;
		}
		case 4: {
			float circleArea = data.SumOfCircleArea();
			cout << "Tong dien tich hinh tron: " << circleArea << endl;
			break;
		}
		case 5: {
			float recArea = data.SumOfRectangleArea();
			cout << "Tong dien tich hinh chu nhat: " << recArea << endl;
			break;
		}
		case 6: {
			Shape* result = data.findMaxCircleArea();
			cout << "Hinh tron co dien tich lon nhat: ";
			result->print();
			break;
		}
		case 7: {
			data.writeToFile(input);
			cout << "Da ghi thong tin" << endl;
			break;
		}
		case 8: {
			data.ReadFromFile(input);
			break;
		}
		default:
			cout << "Chuong trinh ket thuc" << endl;
			break;
		}
	} while (userChoose != 0);


}