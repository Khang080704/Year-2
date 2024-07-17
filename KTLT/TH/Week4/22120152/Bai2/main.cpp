#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;

struct PhanSo
{
	int tu, mau;
};

void XuatPhanSo(PhanSo* pPS) {
	cout << pPS->tu << "/" << pPS->mau;
}

int find_first_of(const char* a, char b) {
	int index = 0;
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == b) {
			return index;
		}
		else {
			index++;
		}
	}
	return index;
}


PhanSo* changeToFraction(const char* s) {
	int length = strlen(s);
	int needle = find_first_of(s, '/');
	int startPos = 0;
	PhanSo* ps = new PhanSo;
	char tuSo[10];
	strncpy_s(tuSo, s + startPos, needle);
	ps->tu = atoi(tuSo);
	
	char mauSo[10];
	startPos = needle;
	strncpy_s(mauSo, s + startPos + 1, (size_t)length - startPos);
	ps->mau = atoi(mauSo);
	return ps;
}

PhanSo* tong(PhanSo* x, PhanSo* y) {
	PhanSo* sum = new PhanSo;

	sum->tu = x->tu * y->mau + y->tu * x->mau;
	sum->mau = x->mau * y->mau;
	return sum;
}

PhanSo* TongPhanSoTuChuoi(const char* s)
{
	size_t length = strlen(s);
	int p = find_first_of(s, '+');
	int startPos = 0;
	char first[100];
	strncpy_s(first, s + startPos, p);
	PhanSo* x = changeToFraction(first);
	

	char second[100];
	startPos = p;
	strncpy_s(second, s + startPos + 1, length - startPos);
	PhanSo* y = changeToFraction(second);
	PhanSo* sum = tong(x, y);
	return sum;
}
void rutGon(PhanSo*& x) {
	int a = x->tu;
	int b = x->mau;
	while (a != b) {
		if (a > b) {
			a = a - b;
		}
		else {
			b = b - a;
		}
	}
	x->tu = x->tu / a;
	x->mau = x->mau / a;
}

int main()
{
	PhanSo* pPS = TongPhanSoTuChuoi("14/56+24/45");
	printf("Tong cua Phan so duoc tu chuoi '14/56+24/45' la:\n");
	rutGon(pPS);
	XuatPhanSo(pPS);
}