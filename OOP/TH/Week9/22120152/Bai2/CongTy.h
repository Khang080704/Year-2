#pragma once
#include"NVCongNhat.h"
#include"NVSanXuat.h"
#include"Linked_list.h"
#include<vector>
#include<fstream>

class CongTy
{
private:
	vector<NhanVien*> Employee;
	int size;
	
	int demLuongLonHonLuongTrungBinh() {
		float average = averageSalary();
		int count = 0;
		for (int i = 0; i < Employee.size(); i++) {
			if (Employee[i]->getSalary() * 1.0 > average) {
				count++;
			}
		}
		return count;
	}
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
	//write in4 to file
	void WriteToFile(string filePath);
	//read from file
	void ReadFromFile(string filePath);
	//tinh luong cho tung loai nhan vien
	int NVCNSalary();
	int NVSXSalary();
	//tim nhan vien co luong lon nhat
	NhanVien* findMaxSalary();
	void writeSalaryToFile(string fname);
	void readSalaryFromFile(string fname);
	void sortByID();
	~CongTy();
	
};

