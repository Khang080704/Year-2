#pragma once
#include"NhanVien.h"
class NVCongNhat :public NhanVien {
private:
	int workDay;
	string type;
public:
	NVCongNhat() {
		workDay = 0;
		type = "Nhan vien cong nhat";
	}
	int getSalary();
	void outputInfor();
	void inputInfor();
};


