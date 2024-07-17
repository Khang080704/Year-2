#include<iostream>
using namespace std;

struct ThoiGian
{
	int gio, phut, giay;
};
ThoiGian* TaoThoiGian(int h, int m, int s)
{
	ThoiGian* p = new ThoiGian;
	if (p == NULL) {
		cout << "Khong du vung nho";
		return NULL;
	}
	else {
		p->gio = h;
		p->phut = m;
		p->giay = s;
		return p;
	}
}
void HopLeThoiGian(ThoiGian*& pTG)
{
	if (pTG->giay > 60) {
		int first = pTG->giay % 60;
		int second = pTG->giay / 60;
		pTG->phut += second;
		pTG->giay = first;
	}
	else {
		if (pTG->phut > 60) {
			int first = pTG->phut % 60;
			int second = pTG->phut / 60;
			pTG->gio += second;
			pTG->phut = first;
		}
	}
}
void PrintTG(ThoiGian* pTG)
{
	cout << pTG->gio << ":" << pTG->phut << ":" << pTG->giay << endl;
}
ThoiGian* KhoangCachThoiGian(ThoiGian* pTG1, ThoiGian* pTG2)
{
	ThoiGian* newtime = new ThoiGian;
	if (pTG2->gio > pTG1->gio) {
		newtime->gio = pTG2->gio - pTG1->gio;
		if (pTG2->giay > pTG1->giay) {
			newtime->giay = pTG2->giay - pTG1->giay;
		}
		else {
			newtime->giay = 60 + pTG2->giay - pTG1->giay;
			newtime->phut--;
		}

		if (pTG2->phut > pTG1->phut) {
			newtime->phut = pTG2->phut - pTG1->phut;
		}
		else {
			newtime->phut = 60 + pTG2->phut - pTG1->phut;
			newtime->gio--;
		}
	}

	if (pTG1->gio > pTG2->gio) {
		newtime->gio = pTG1->gio - pTG2->gio;

		if (pTG1->giay > pTG2->giay) {
			newtime->giay = pTG1->giay - pTG2->giay;
		}
		else {
			newtime->giay = 60 + pTG1->giay - pTG2->giay;
			newtime->phut--;
		}

		if (pTG1->phut > pTG2->phut) {
			newtime->phut = pTG1->phut - pTG2->phut;
		}
		else {
			newtime->phut = 60 + pTG1->phut - pTG2->phut;
			newtime->gio--;
		}

	}
	return newtime;
}


int main()
{
	srand(time(0));
	ThoiGian* pTG1, * pTG2;
	pTG1 = TaoThoiGian(rand() % 100, rand() % 100, rand() % 100);
	pTG2 = TaoThoiGian(rand() % 100, rand() % 100, rand() % 100);
	cout << "Thoi gian 1: " << endl;
	PrintTG(pTG1);
	cout << "Thoi gian 2: " << endl;
	PrintTG(pTG2);
	HopLeThoiGian(pTG1);
	HopLeThoiGian(pTG2);
	cout << "Thoi gian sau khi lam hop le: " << endl;
	cout << "Thoi gian 1: " << endl;
	PrintTG(pTG1);
	cout << "Thoi gian 2: " << endl;
	PrintTG(pTG2);

	ThoiGian* p = KhoangCachThoiGian(pTG1, pTG2);
	cout << "Khoang cach giua 2 thoi gian tren:" << endl;
	PrintTG(p);
	return 0;
}