#pragma once
#include"NhanVien.h"
class NVCongNhat :public NhanVien {
private:
	int workDay;
public:
	NVCongNhat() : NhanVien("Nhan vien cong nhat") {
		workDay = 0;
	}
	int getSalary();
	void outputInfor();
	void inputInfor();
};


