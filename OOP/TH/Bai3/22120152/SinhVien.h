#pragma once
#include<string>
#include<iostream>
#include<fstream>
using namespace std;



class SinhVien
{
private:
	string name;
	string id;
	string birthday;
	double midTerm, finalTerm, practice;
public:
	SinhVien(string name, string id, string birrthDay
		,double midTerm, double finalTerm, double practice);
	SinhVien();
	SinhVien(SinhVien& temp);
	double average();
	void upDate();
	void showInFile();
	void show();
	void ranking();
};

