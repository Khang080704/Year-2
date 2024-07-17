#pragma once
#include"NhanVien.h"
class NVSanXuat : public NhanVien
{
private:
	int productNumber;
public:
	NVSanXuat() : NhanVien("Nhan vien san xuat") {
		productNumber = 0;
	}
	int getSalary();
	void inputInfor();
	void outputInfor();
};
