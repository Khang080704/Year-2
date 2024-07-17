#define _CRT_SECURE_NO_WARNINGS
#include"TaiKhoan.h"
void Nhap(TaiKhoan& tk) {
	//Nhap ten dang nhap
	do {
		cout << "Nhap ten dang nhap: ";
		cin.get(tk.tenDangNhap, 30, '\n');
		cin.ignore();
	} while (kiemTraTenDangNhap(tk.tenDangNhap) == 0);
	
	//Nhap mat khau
	do
	{
		cout << "Nhap mat khau: ";
		cin.get(tk.matKhau, 30, '\n');
		cin.ignore();
	} while (KiemTraMatKhau(tk.matKhau) == 0);

	//Nhap ho ten
	do
	{
		cout << "Nhap ho ten: ";
		cin.get(tk.hoTen, 50, '\n');
		cin.ignore();
	} while (kiemTraHoTen(tk.hoTen) == 0);

	//Nhap email
	do
	{
		cout << "Nhap email: ";
		cin.get(tk.email, 50, '\n');
		cin.ignore();
	} while (kiemTraEmail(tk.email) == 0);

	//Nhap ngay thang sinh
	nhapNgayThangNam(tk.ntns);
}
int kiemTraTenDangNhap(char tenDangNhap[]) {
	//buoc 1: copy qua chuoi khac, khong thay doi chuoi hien tai
	char s[31];
	strcpy_s(s, tenDangNhap);
	//Buoc 2: chuyen sang chu thuong
	_strlwr(s);
	//Buoc 3: dung ham strstr kiem tra chuoi co nam trong chuoi
	char* p = strstr(s, "admin");
	if (p == NULL) {// co
		return 1;
	}
	return 0;
}
int KiemTraMatKhau(char matKhau[]) {
	//buoc 1: mat khau phai lon hon 6 ki tu
	int doDai = strlen(matKhau);
	if (doDai < 6) {
		return 0;
	}
	
	//Co ki tu hoa
	int coKiTuHoa = 0;
	for (int i = 0; i < doDai; i++) {
		if (matKhau[i] >= 'A' && matKhau[i] <= 'Z') {
			coKiTuHoa = 1;
			break;
		}
	}
	if (coKiTuHoa == 0) {
		return 0;
	}

	//Co ki tu chu cai
	int coKiTu = 0;
	for (int i = 0; i < doDai; i++) {
		if (matKhau[i] >= 'a' && matKhau[i] <= 'z') {
			coKiTu = 1;
			break;
		}
		if (matKhau[i] >= 'A' && matKhau[i] <= 'Z') {
			coKiTu = 1;
			break;
			
		}
	}
	if (coKiTu == 0) {
		return 0;
	}

	//Co ki tu so
	int coSo = 0;
	for (int i = 0; i < doDai; i++) {
		if (matKhau[i] >= '0' && matKhau[i] <= '9') {
			coSo = 1;
			break;
		}
	}
	if (coSo == 0) {
		return 0;
	}
	
	//Co dau
	int coDau = 0;
	for (int i = 0; i < doDai; i++) {
		if (matKhau[i] == ',' || matKhau[i] == '.' || matKhau[i] == ':' || matKhau[i] == '?' || 
			matKhau[i] == '=' || matKhau[i] == '_') {
			coDau = 1;
			break;
		}
	}
	if (coSo == 0) {
		return 0;
	}
	
	return 1;
}
int kiemTraHoTen(char hoTen[]) {
	int coKhoangTrang = 0;
	int doDai = strlen(hoTen);
	for (int i = 0; i < doDai; i++) {
		if (hoTen[i] == ' ') {
			coKhoangTrang = 1;
			break;
		}
	}
	if (coKhoangTrang == 0) {
		return 0;
	}
	return 1;
}
int kiemTraEmail(char email[]) {
	int doDai = strlen(email);
	int coKiTuDacBiet = 0;
	for (int i = 0; i < doDai; i++) {
		if (email[i] == '@') {
			coKiTuDacBiet = 1;
			break;
		}
	}
	if (coKiTuDacBiet == 0) {
		return 0;
	}

	int coDauCham = 0;
	for (int i = 0; i < doDai; i++) {
		if (email[i] == '.') {
			coDauCham = 1;
			break;
		}
	}
	if (coDauCham == 0) {
		return 0;
	}

	return 1;
}
void nhapNgayThangNam(Ngay& ng) {
	cout << "Nhap ngay sinh: "; cin >> ng.ngay;
	cout << "Nhap thang sinh: "; cin >> ng.thang;
	cout << "Nhap nam sinh: "; cin >> ng.nam;
	cin.ignore();
}
void tachHoTen(const char*& ten) {
	
}
void xuat(TaiKhoan tk) {
	cout << "Ten dang nhap: " << tk.tenDangNhap << endl;
	cout << "Mat khau: " << tk.matKhau << endl;
	cout << "Ho ten: " << endl;
	char s[51];
	strcpy_s(s, tk.hoTen);
	stringstream ss(s);
	string buffer;
	while (ss >> buffer) {
		cout << buffer << endl;
	}
	
	cout << "Email: " << tk.email << endl;
	cout << "Tuoi: " << 2024 - tk.ntns.nam << endl;
	cout << endl;
}
int tinhTuoi(TaiKhoan a) {
	return 2024 - a.ntns.nam;
}