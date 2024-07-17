#pragma once
#include"TaiKhoan.h"
void nhapMang(TaiKhoan*& x, int n);
void xuatMang(TaiKhoan* x, int n);
void lietKeTheoTen(TaiKhoan* a, int n, char ten[]);
int themTaiKhoan(TaiKhoan* a, int& n, TaiKhoan tk);
void xoaTaiKhoan(TaiKhoan* a, int& n, char tenDangNhap[]);
int soSanhNhoHon(int a, int b); 
int soSanhLonHon(int a, int b); 
int soSanhTheoChuoiLonHon(char a[], char b[]);
int soSanhTheoChuoiNhoHon(char a[], char b[]);
void sapXepTheoTuoi(TaiKhoan*& a, int n, int(*soSanh)(int,int));
void sapXepTheoHoTen(TaiKhoan*& a, int n, int(*soSanh)(char[], char[]));
void sapXepTheoTenDangNhap(TaiKhoan*& a, int n, int(*soSanh)(char[], char[]));