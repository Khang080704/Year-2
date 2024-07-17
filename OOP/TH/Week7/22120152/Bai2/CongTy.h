#pragma once
#include"NVCongNhat.h"
#include"NVSanXuat.h"
#include<vector>
#include<fstream>

class CongTy
{
private:
	vector<NhanVien*> Employee;
	int size;
public:
	//Constructor
	CongTy();
	CongTy(int);
	//Input
	void input();
	void addEmployee(NhanVien*);
	//Output
	void output();
	//Calculate sum of salary
	int getSumOfSalary();
	//Average Salary
	float averageSalary();
	//Find employee with ID
	void findWithID(string);
	//Find employee with name
	void findWithName(string);
	//count employee
	int countByMonth(int);
	void WriteToFile(string fname);
	void ReadFromFile(string fname);
	~CongTy();
	
};

