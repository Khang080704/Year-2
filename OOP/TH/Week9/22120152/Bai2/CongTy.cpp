#include "CongTy.h"
CongTy::CongTy() {
	size = 0;
}
CongTy::CongTy(int n) {

	size = n;
}
void CongTy::addEmployee(NhanVien* a) {
	Employee.push_back(a);
	
}
void CongTy::input() {
	std::cout << "Nhap so luong nhan vien san xuat: ";
	int n; std::cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		NVSanXuat* a = new NVSanXuat();
		a->inputInfor();
		addEmployee(a);
	}

	std::cout << "Nhap so luong nhan vien cong nhat: ";
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		NVCongNhat* a = new NVCongNhat();
		a->inputInfor();
		addEmployee(a);
	}
	

}
void CongTy::output() {
	for (int i = 0; i < Employee.size(); i++) {
		Employee[i]->outputInfor();
	}
	
}
int CongTy::getSumOfSalary() {
	int sumSalary = 0;

	for (int i = 0; i < Employee.size(); i++) {
		sumSalary += Employee[i]->getSalary();
	}
	
	return sumSalary;
}
float CongTy::averageSalary(){
	float average = 0.0;
	for (int i = 0; i < Employee.size(); i++) {
		average += (float)Employee[i]->getSalary();
	}
	
	return average / Employee.size();
}
void CongTy::findWithID(string ID) {
	vector<NhanVien*> data;
	int isExist = 0;
	for (int i = 0; i < Employee.size(); i++) {
		if (Employee[i]->getID() == ID) {
			data.push_back(Employee[i]);
			isExist++;
		}
	}
	if (isExist == 0) {
		cout << "Khong ton tai nhan vien" << endl;
		return;
	}
	for (int i = 0; i < data.size(); i++) {
		data[i]->outputInfor();
	}
	
}
void CongTy::findWithName(string name) {
	vector<NhanVien*> data;
	int isExist = 0;
	for (int i = 0; i < Employee.size(); i++) {
		if (Employee[i]->getName() == name) {
			data.push_back(Employee[i]);
			isExist++;
		}
	}
	if (isExist == 0) {
		cout << "Khong ton tai nhan vien" << endl;
		return;
	}
	for (int i = 0; i < data.size(); i++) {
		data[i]->outputInfor();
	}
}
int CongTy::countByMonth(int month) {
	int count = 0;
	for (int i = 0; i < Employee.size(); i++) {
		if (Employee[i]->getBirthDay().month == month) {
			count++;
		}
	}
	
	return count;
}
void CongTy::WriteToFile(string filePath) {
	ofstream writter(filePath, ios::binary | ios::out);
	for (int i = 0; i < Employee.size(); i++) {
		writter.write((const char*)&Employee[i], sizeof(NhanVien));
	}
	writter.close();
	
}

void CongTy::ReadFromFile(string filePath) {
	ifstream reader(filePath, ios::binary | ios::in);
	vector<NhanVien*> data(Employee.size());
	for (int i = 0; i < Employee.size(); i++) {
		reader.read((char*)&data[i], sizeof(NhanVien*));
	}

	for (int i = 0; i < data.size(); i++) {
		data[i]->outputInfor();
	}
	reader.close();
	
}
int CongTy::NVCNSalary() {
	int NVCN = 0;
	for (int i = 0; i < Employee.size(); i++) {
		if (Employee[i]->getType() == "Nhan vien cong nhat") {
			NVCN += Employee[i]->getSalary();
		}
	}
	return NVCN;
}
int CongTy::NVSXSalary() {
	int NVSX = 0;
	for (int i = 0; i < Employee.size(); i++) {
		if (Employee[i]->getType() == "Nhan vien san xuat") {
			NVSX += Employee[i]->getSalary();
		}
	}
	return NVSX;
}
NhanVien* CongTy::findMaxSalary() {
	NhanVien* result = Employee[0];
	for (int i = 0; i < Employee.size(); i++) {
		if (result->getSalary() < Employee[i]->getSalary()) {
			result = Employee[i];
		}
	}
	return result;
}
void CongTy::sortByID() {
	for (int i = 0; i < Employee.size(); i++) {
		for (int j = i + 1; j < Employee.size(); j++) {
			if (Employee[i]->getID() > Employee[j]->getID()) {
				NhanVien* temp = Employee[i];
				Employee[i] = Employee[j];
				Employee[j] = temp;
			}
		}
	}
}
void CongTy::writeSalaryToFile(string fname) {
	ofstream writter(fname, ios::binary | ios::out);
	float average = averageSalary();
	int count = 0;
	for (int i = 0; i < Employee.size(); i++) {
		if (Employee[i]->getSalary() * 1.0 > average) {
			writter.write((const char*)&Employee[i], sizeof(NhanVien));
		}
	}
	writter.close();
}
void CongTy::readSalaryFromFile(string fname) {
	ifstream reader(fname, ios::binary | ios::in);
	int count = demLuongLonHonLuongTrungBinh();
	vector<NhanVien*> data(count);

	for (int i = 0; i < count; i++) {
		reader.read((char*)&data[i], sizeof(NhanVien*));
	}
	for (int i = 0; i < count; i++) {
		data[i]->outputInfor();
	}
	reader.close();
}
CongTy::~CongTy() {
	for (int i = 0; i < Employee.size(); i++) {
		delete Employee[i];
	}
}
