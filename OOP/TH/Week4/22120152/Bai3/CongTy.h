#pragma once
#include"NVCongNhat.h"
#include"NVSanXuat.h"

class CongTy
{
private:
	NVCongNhat* NVCN;
	NVSanXuat* NVSX;
	int SLSX;
	int SLCN;
public:
	CongTy();
	CongTy(int);
	void input(string);
	void output();
	int getSumOfSalary();
	float averageSalary();
	void findWithID(string);
	void findWithName(string);
	int countByMonth(int);
	~CongTy();
	
};

