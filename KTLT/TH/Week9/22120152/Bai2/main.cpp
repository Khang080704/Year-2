#define _CRT_SECURE_NO_WARNINGS
#include"SinhVien.h"
#include<sstream>
struct LopHoc {
	Linked_List lop;
};
void khoiTaoLop(LopHoc& l);
void themSinhVien(LopHoc& l, SinhVien t);
void inHoten(SinhVien t);
void inHoTenId(SinhVien t);
void inTatCa(SinhVien t);
void inDanhSach(LopHoc l);
void inTen(LopHoc l);
void inTenId(LopHoc l);
int SoSanhTheoDiem(SinhVien a, SinhVien b);
void tachten(char hoten[], char ten[]);
int SoSanhTheoTen(SinhVien a, SinhVien b);
int SoSanhTheoMSSV(SinhVien a, SinhVien b);
void xoaLopHoc(LopHoc& info); 

void sapXepLopHoc(LopHoc& info,int n ,int (*DieuKien)(SinhVien a, SinhVien b)) {
	for (Node* i = info.lop.head; i != NULL; i = i->pNext) {
		for (Node* j = i->pNext; j != NULL; j = j->pNext) {
			if (DieuKien(i->data, j->data) == 1) {
				SinhVien temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}

void DuoiHocSinhVien(LopHoc& info) {
	Node* i = info.lop.head;
	while (i != NULL) {
		if (i->data.score < 5) {
			Node* j = i;
			i = i->pNext;
			removeByIndex(info.lop, j);
		}
		else {
			i = i->pNext;
		}
	}
}

void themSinhVien(LopHoc& info, SinhVien t, int (*DieuKien)(SinhVien a, SinhVien b)) {
	Node* p = createNode(t);
	for (Node* i = info.lop.head; i != NULL; i = i->pNext) {
		if (DieuKien(i->data, t) == -1 && DieuKien(i->pNext->data,t) != -1) {
			addByIndex(info.lop, i, p);
			break;
		}
	}
}

void divideClass(LopHoc& info, LopHoc& first, LopHoc& second, int n) {
	Node* p = info.lop.head;
	for (int i = 1; i <= n / 2; i++) {
		themSinhVien(first, p->data);
		p = p->pNext;
	}
	for (int i = n / 2 + 1; i <= n; i++) {
		themSinhVien(second, p->data);
		p = p->pNext;
	}
}
void mergeClass(LopHoc& sum, LopHoc first, LopHoc second) {
	for (Node* i = first.lop.head; i != NULL; i = i->pNext) {
		themSinhVien(sum, i->data);
	}
	for (Node* i = second.lop.head; i != NULL; i = i->pNext) {
		themSinhVien(sum, i->data);
	}
}

void GhiFileNhiPhan(const char* filePath, LopHoc info)
{
	ofstream writter(filePath, ios::binary | ios::out);
	for (Node* i = info.lop.head; i != NULL; i = i->pNext) {
		writter.write((const char*)&i->data, sizeof(SinhVien));
	}
	writter.close();
}
void DocFileNhiPhan(const char* filePath) {
	ifstream reader(filePath, ios::binary | ios::in);
	SinhVien temp;
	while (reader.read((char*)&temp, sizeof(SinhVien))) {
		inTatCa(temp);
	}
	reader.close();
}
void showOption() {
	cout << "Chuong trinh quan li hinh ve: " << endl;
	cout << "1. Khoi tao lop hoc: " << endl;
	cout << "2. Them sinh vien vao lop hoc: " << endl;
	cout << "3. Xuat danh sach sinh vien: " << endl;
	cout << "4. Ghi du lieu vao file nhi phan: " << endl;
	cout << "5. Sap xep sinh vien theo tieu chi: " << endl;
	cout << "6. Duoi hoc sinh vien theo diem trung binh: " << endl;
	cout << "7. Xoa lop hoc: " << endl;
	cout << "8. Them 1 sinh vien vao lop da duoc sap xep: " << endl;
	cout << "9. Tach 1 lop hoc thanh 2 lop: " << endl;
	cout << "10. Gop 2 lop thanh 1 lop" << endl;
	cout << "0. Thoat" << endl;
}
void tieuChiXuat() {
	cout << "1. Xuat tat ca" << endl;
	cout << "2. Xuat ho ten" << endl;
	cout << "3. Xuat ho ten - id" << endl;
}
void tieuChi() {
	cout << "1. MSSV" << endl;
	cout << "2. Ho ten" << endl;
	cout << "3. Diem" << endl;
}
int main()
{
	LopHoc data;
	khoiTaoLop(data);
	int n = 0;
	int tieuChiSapXep = 0;
	showOption();
	
	
	LopHoc l1, l2;
	khoiTaoLop(l1);
	khoiTaoLop(l2);
	int userChoose = 0;
	do {
		cout << "Chon chuc nang: ";
		cin >> userChoose;
		cin.ignore();
		switch (userChoose)
		{
		case 1:
		{
			khoiTaoLop(data);
			cout << "Khoi tao thanh cong" << endl;
			break;
		}
		case 2: {
			cout << "Nhap so luong sinh vien: ";
			cin >> n;
			cin.ignore();

			for (int i = 0; i < n; i++) {
				cout << "Nhap thong tin sinh vien " << i + 1 << ": " << endl;
				SinhVien temp;
				nhapSinhVien(temp);
				themSinhVien(data, temp);
			}
			break;
		}
		case 3: {
			tieuChiXuat();
			cout << "Chon tieu chi: ";
			int tieuChi; cin >> tieuChi;
			switch (tieuChi)
			{
			case 1: {
				inDanhSach(data); break;
			}
			case 2: {
				inTen(data);
				break;
			}
			case 3: {
				inTenId(data);
				break;
			}


			default:
				break;
			}
			break;
		}
		case 4: {
			const char* output = "output.txt";
			GhiFileNhiPhan(output, data);
			cout << "Da ghi du lieu vao file nhi phan" << endl;
			break;
		}
		case 5: {
			tieuChi();
			cout << "Chon tieu chi: ";
			cin >> tieuChiSapXep;
			switch (tieuChiSapXep)
			{
			case 1: {
				sapXepLopHoc(data, n, SoSanhTheoMSSV);
				break;
			}
			case 2: {
				sapXepLopHoc(data, n, SoSanhTheoTen);
				break;
			}
			case 3: {
				sapXepLopHoc(data, n, SoSanhTheoDiem);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 6: {
			DuoiHocSinhVien(data);
			cout << "Da duoi hoc sinh vien" << endl;
			break;
		}
		case 7: {
			xoaLopHoc(data);
			cout << "Da xoa lop hoc" << endl;
			break;
		}
		case 8: {
			SinhVien temp;
			nhapSinhVien(temp);
			if (tieuChiSapXep == 1) {
				themSinhVien(data, temp, SoSanhTheoMSSV);
			}
			else if (tieuChiSapXep == 2) {
				themSinhVien(data, temp, SoSanhTheoTen);
			}
			else {
				themSinhVien(data, temp, SoSanhTheoDiem);
			}
			break;
		}
		case 9: {

			divideClass(data, l1, l2, n);
			cout << "Lop 1:" << endl;
			inDanhSach(l1);
			cout << "Lop 2: " << endl;
			inDanhSach(l2);
			break;
		}
		case 10: {
			LopHoc sum;
			khoiTaoLop(sum);
			mergeClass(sum, l1, l2);
			cout << "Lop hoc da duoc gop: " << endl;
			inDanhSach(sum);
			break;
		}

		default:
			break;
		}
	}
	while (userChoose != 0);
	
	
}

void khoiTaoLop(LopHoc& l) {
	initLinkedList(l.lop);
}
void themSinhVien(LopHoc& l, SinhVien t) {
	addLast(l.lop, t);
}
void inHoten(SinhVien t) {
	cout << t.name << endl;
}
void inHoTenId(SinhVien t) {
	cout << t.name << " - " << t.id << endl;
}
void inTatCa(SinhVien t) {
	cout << t.name << " - " << t.id << " - " << t.score << endl;
}
void inDanhSach(LopHoc l) {
	printList(l.lop, inTatCa);
}
void inTen(LopHoc l) {
	printList(l.lop, inHoten);
}
void inTenId(LopHoc l) {
	printList(l.lop, inHoTenId);
}

int SoSanhTheoDiem(SinhVien a, SinhVien b) {
	if (a.score > b.score) {
		return 1;
	}
	else {
		return -1;
	}
}

void tachten(char* hoten, char* ten) {
	for (int i = strlen(hoten) - 1; i >= 0; i--) {
		if (hoten[i] == ' ') {
			strcpy(ten, hoten + 1 + i);
			break;
		}
	}
}
int SoSanhTheoTen(SinhVien a, SinhVien b) {
	stringstream ss(a.name);
	string buffer;
	
	char x[255];
	char y[255];
	tachten(a.name, x);
	tachten(b.name, y);
	return strcmp(x, y);
}
int SoSanhTheoMSSV(SinhVien a, SinhVien b) {
	return strcmp(a.id, b.id);
}

void xoaLopHoc(LopHoc& info) {
	XoaDanhSach(info.lop);
}