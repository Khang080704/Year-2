#include "CongTy.h"
CongTy::CongTy(int n) {
	NVSX = new NVSanXuat[n];
	NVCN = new NVCongNhat[n];
	SLSX = SLCN = 0;
}
void CongTy::input(string type) {

	if (type == "SX") {
		NVSX[SLSX].inputInfor();
		SLSX++;
	}
	else {
		if (type == "CN") {
			NVCN[SLCN].inputInfor();
			SLCN++;
		}
	}

}
void CongTy::output() {
	for (int i = 0; i < SLSX; i++) {
		NVSX[i].outputInfor();
	}
	cout << endl;
	for (int i = 0; i < SLCN; i++) {
		NVCN[i].outputInfor();
	}
}
int CongTy::getSumOfSalary() {
	int sumSalary = 0;
	for (int i = 0; i < SLSX; i++) {
		sumSalary += NVSX[i].getSalary();
	}
	for (int i = 0; i < SLCN; i++) {
		sumSalary += NVCN[i].getSalary();
	}
	return sumSalary;
}
float CongTy::averageSalary(){
	float average = 0.0;
	for (int i = 0; i < SLSX; i++) {
		average += (float)NVSX[i].getSalary();
	}
	for (int i = 0; i < SLCN; i++) {
		average += (float)NVCN[i].getSalary();
	}
	return average / (SLSX + SLCN);
}
void CongTy::findWithID(string ID) {
	int isExist = 0;
	for (int i = 0; i < SLSX; i++) {
		if (NVSX[i].ID == ID) {
			NVSX[i].outputInfor();
			isExist++;
		}
	}
	for (int i = 0; i < SLCN; i++) {
		if (NVCN[i].ID == ID) {
			NVCN[i].outputInfor();
			isExist++;
		}
	}
	if (isExist == 0) {
		cout << "Khong ton tai nhan vien" << endl;
	}
}
void CongTy::findWithName(string name) {
	int isExist = 0;
	for (int i = 0; i < SLSX; i++) {
		if (NVSX[i].fullName == name) {
			NVSX[i].outputInfor();
			isExist++;
		}
	}
	for (int i = 0; i < SLCN; i++) {
		if (NVCN[i].fullName == name) {
			NVCN[i].outputInfor();
			isExist++;
		}
	}
	if (isExist == 0) {
		cout << "Khong ton tai nhan vien" << endl;
	}
}
int CongTy::countByMonth(int month) {
	int count = 0;
	for (int i = 0; i < SLSX; i++) {
		if (NVSX[i].birthDay.month == month) {
			count++;
		}
	}
	for (int i = 0; i < SLCN; i++) {
		if (NVCN[i].birthDay.month == month) {
			count++;
		}
	}
	return count;
}
CongTy::~CongTy() {
	delete[] NVCN;
	delete[] NVSX;
}
