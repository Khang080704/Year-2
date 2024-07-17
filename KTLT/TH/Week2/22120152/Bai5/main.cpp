#include <iostream>
#include<math.h>
using namespace std;

struct NgayThangNam
{
	int ngay, thang, nam;
};

NgayThangNam* CreateDay(int yy, int mm, int dd)
{
	NgayThangNam* newday = new NgayThangNam;
	newday->ngay = dd;
	newday->thang = mm;
	newday->nam = yy;

	return newday;
}

void Print(NgayThangNam* pTG)
{
	cout << "Ngay " << pTG->ngay << " thang " << pTG->thang << " nam " << pTG->nam;
}

int checkLeapYear(int year) {
	int result;
	if (year <= 0 || year > 100000)   result = -1;
	else {
		if (year % 4 != 0) {
			result = 0;
		}
		else {
			if (year % 100 != 0) {
				result = 1;
			}
			else {

				if (year % 400 == 0) {
					result = 1;
				}
				else result = 0;

			}
		}

	}
	return result;
}


//so ngay trong thang
int SoNgayTrongThang(int month, int year) {
	if ((0 < month) && (month <= 12)) {
		switch (month) {
		case 1: case 3:case 5:case 7:case 8:
		case 10:case 12: {
			return  31;
			break; }

		case 2: {
			if (checkLeapYear(year) == 1) {
				return  29;
			}
			else return  28;
			break;
		}

		case 4:case 6: case 9: case 11: {
			return 30;
			break;
		}

		}
	}

}
int KhoangCachGiuaHaiNgay(NgayThangNam* pNgay1, NgayThangNam* pNgay2) {
	// Chuyển đổi ngày tháng năm thành số ngày tính từ 1/1/1
	int dn1 = pNgay1->ngay + 365 * pNgay1->nam + (pNgay1->nam - 1) / 4 - (pNgay1->nam - 1) / 100 + (pNgay1->nam - 1) / 400;
	
	for (int i = 1; i < pNgay1->thang; i++)
		dn1 += SoNgayTrongThang(i, pNgay1->nam);

	int dn2 = pNgay2->ngay + 365 * pNgay2->nam + (pNgay2->nam - 1) / 4 - (pNgay2->nam - 1) / 100 + (pNgay2->nam - 1) / 400;
	for (int i = 1; i < pNgay2->thang; i++)
		dn2 += SoNgayTrongThang(i, pNgay2->nam);

	// Tính khoảng cách giữa hai số ngày
	int khoangCach = abs(dn2 - dn1);
	return khoangCach;
}


int main()
{
	NgayThangNam* pDay1;
	NgayThangNam* pDay2;

	int day1, month1, year1;
	int day2, month2, year2;

	cout << "nhap vao ngay, thang, nam 1: ";
	cin >> day1 >> month1 >> year1;
	pDay1 = CreateDay(year1, month1, day1);
	Print(pDay1);

	cout << endl;

	cout << "nhap vao ngay, thang, nam 2: ";
	cin >> day2 >> month2 >> year2;
	pDay2 = CreateDay(year2, month2, day2);
	Print(pDay2);

	cout << endl << endl;

	cout << "Khoang cach 2 thoi gian tren: " << KhoangCachGiuaHaiNgay(pDay1, pDay2) << " ngay";

	return 0;
}