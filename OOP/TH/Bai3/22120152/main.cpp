#include "QLSinhVien.h"

//Doc tu file ra
string file_in = "input.txt";
ifstream reader(file_in, ios::in);
const int ATTRIBUTE = 6;

string file_out = "output.txt";
ofstream ghi_de(file_out, ios::out);


void readDataFromFile(QLSinhVien& data) {
	string* buffer = new string[ATTRIBUTE];
	int count = 0;
	while (!reader.eof()) {
		for (int i = 0; i < ATTRIBUTE; i++) {
			getline(reader, buffer[i]);
		}
		count++;
		SinhVien a(buffer[0], buffer[1], buffer[2],
			stod(buffer[3]), stod(buffer[4]), stod(buffer[5]));
		data.add(a);
	}
	reader.close();
	delete[] buffer;
}

void updateData(QLSinhVien& data,SinhVien a) {
	a.upDate();
	data.add(a);
}

void UnderAverage(QLSinhVien data) {
	data.findUnderAverage();
}

int main() {
	QLSinhVien data;
	cout << "Chuong trinh quan li sinh vien: " << endl;
	cout << "1. Doc danh sach tu tap tin. " << endl;
	cout << "2. In danh sach sinh vien ra man hinh" << endl;
	cout << "3. Them sinh vien moi " << endl;
	cout << "4. Ghi danh sach sinh vien co diem trung binh nho hon diem trung binh lop" << endl;
	cout << "5. Xep loai sinh vien" << endl;
	cout << "7. Thoat chuong trinh" << endl;
	int userChoose = 0;
	do {
		cout << "Chon chuc nang: ";
		cin >> userChoose;
		switch (userChoose)
		{
		case 1: {
			readDataFromFile(data);
			cout << "Da doc thanh cong !" << endl;
			break;
		}
		case 2: {
			if (data.isEmpty()) {
				cout << "Chua co thong tin";
				break;
			}
			else {
				cout << "Danh sach sinh vien: " << endl;
				data.display();
				break;
			}
			
		}
		case 3: {
			string name, id, birthDay;
			double practice, mid, final;
			cin.ignore();
			cout << "Nhap ho ten: "; getline(cin, name);
			cout << "Nhap id: "; getline(cin, id);
			cout << "Nhap ngay thang nam sinh dd/mm/yy: "; getline(cin, birthDay);
			cout << "Nhap diem tuong ung: ";
			cin >> practice >> mid >> final;
			SinhVien a(name, id, birthDay, practice, mid, final);
			updateData(data, a);
			cout << "Da cap nhat sinh vien thanh cong" << endl;
			break;
		}
		case 4: {
			if (data.isEmpty()) {
				cout << "Chua co thong tin";
				break;
			}
			else {
				ghi_de << endl;
				ghi_de.close();
				data.findUnderAverage();
				break;
			}
		}
		case 5: {
			data.xepLoai();
		}

		default:
			break;
		}
	} while (userChoose != 7);


 }