#pragma once
#include<iostream>
using namespace std;
const float PI = 3.14156;
struct Diem
{
	float x, y;
};
struct DuongTron
{
	Diem* tam;
	float banKinh;
};
DuongTron* TaoDuongTron(float xV, float yV, float rV);
void XoaDuongTron(DuongTron* p);
void PrintDuongTron(DuongTron* p);
float tinhChuVi(DuongTron* p);
float tinhDienTich(DuongTron* p);
DuongTron* ChuViLonNhat(DuongTron** l, int n);
float TongDienTich(DuongTron** l, int n);
int XuatCacDuongTronDTLonHonTB(DuongTron** l, int n);
void XuatDuongTronChuViGiam(DuongTron** l, int n);
void XoaDsDuongTron(DuongTron** l, int n);