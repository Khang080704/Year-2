#pragma once
#include"NhanVien.h"
class NVSanXuat : public NhanVien
{
private:
	int productNumber;
	string type;
public:
	NVSanXuat() : NhanVien() {
		productNumber = 0;
		type = "Nhan vien san xuat";
	}
	int getSalary();
	void inputInfor();
	void outputInfor();
};
