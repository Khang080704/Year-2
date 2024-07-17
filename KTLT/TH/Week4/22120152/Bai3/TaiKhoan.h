#pragma once
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<sstream>
using namespace std;

struct Ngay {
	int ngay, thang, nam;
};
struct TaiKhoan {
	char tenDangNhap[31];
	char matKhau[31];
	char hoTen[51];
	char email[51];
	Ngay ntns;
};
void Nhap(TaiKhoan& tk);
int kiemTraTenDangNhap(char tenDangNhap[]);
int KiemTraMatKhau(char matKhau[]);
int kiemTraHoTen(char hoTen[]);
int kiemTraEmail(char email[]);
void nhapNgayThangNam(Ngay& ng);
void xuat(TaiKhoan tk);
void tachHoTen(const char*& ten);