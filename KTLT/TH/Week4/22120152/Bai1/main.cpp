#include<iostream>
#include<cstring>
#include<sstream>

const int MAXLENGTH = 100;
using namespace std;

struct Nguoi {
	char HOTEN[MAXLENGTH];
	char DiaChi[MAXLENGTH];
};

Nguoi* TaoNguoi(const char* pHt, const char* pDc) {
	Nguoi* people = new Nguoi;
	strcpy_s(people->HOTEN, pHt);
	strcpy_s(people->DiaChi, pDc);
	return people;
}

void XuatNguoi(Nguoi* pN) {
	cout << pN->HOTEN << " [" << pN->DiaChi << "]";
}

void ChuanHoaTen(Nguoi*& pN) {
	stringstream ss(pN->HOTEN);
	strcpy_s(pN->HOTEN, "");
	char buffer[100];
	while (ss >> buffer) {
		
		if (buffer[0] >= 97) {
			buffer[0] -= 32;
		}
		for (int i = 1; i < strlen(buffer); i++) {
			if (buffer[i] < 97) {
				buffer[i] += 32;
			}
		}
		strcat_s(buffer, " ");
		strncat_s(pN->HOTEN, buffer, MAXLENGTH);
	}

}

int main()
{
	int n = 3;
	Nguoi** pDsNguoi = (Nguoi**)malloc(n * sizeof(Nguoi*));
	pDsNguoi[0] = TaoNguoi(" lE tHI duNG ", "HCM");
	pDsNguoi[1] = TaoNguoi(" ngUYen VAN ngUyEn ", "HN");
	pDsNguoi[2] = TaoNguoi(" tRan trung trUc ", "DN");
	printf("Danh sach Nguoi moi tao:\n");
	for (int i = 0; i < n; ++i)
	{
		XuatNguoi(pDsNguoi[i]);
		cout << endl;
	}

	printf("\nDanh sach Nguoi sau khi chuan hoa ten:\n");
	for (int i = 0; i < n; ++i)
	{
		ChuanHoaTen(pDsNguoi[i]);
		XuatNguoi(pDsNguoi[i]);
		cout << endl;
	}
}