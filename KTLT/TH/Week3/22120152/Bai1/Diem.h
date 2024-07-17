#pragma once
#ifndef _DIEM_H_
#define _DIEM_H_
#include<iostream>
#include<cmath>
using namespace std;
struct Diem
{
	float x, y;
};
void NhapDiem(Diem* d);
void XuatDiem(Diem d);
float khoangCach(Diem a, Diem b);
#endif
