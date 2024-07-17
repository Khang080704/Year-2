#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define MAXLEN 100
struct SinhVien
{
	int MSSV;
	char HoTen[51];
};
void SVToString(const SinhVien& sv)
{
	/// xuất thông tin sinh viên ra chuỗi
	/// định dạng: <MSSV> - <HoTen>
	cout << sv.MSSV << " - " << sv.HoTen;
	cout << endl;
}
void PrintArr(SinhVien* arr, const int& n)
{
	for (int i = 0; i < n; i++)
	{
		SVToString(arr[i]);
	}
}
/// định nghĩa con trỏ hàm
typedef int(*SVComparer)(SinhVien, SinhVien);
/// hàm so sánh sinh viên dựa vào mssv
int SVC1(SinhVien sv1, SinhVien sv2)
{
	if (sv1.MSSV > sv2.MSSV)
	{
		return 1;
	}
	if (sv1.MSSV < sv2.MSSV)
	{
		return -1;
	}
	return 0;
}
/// hàm so sánh sinh viên dựa vào họ tên
int SVC2(SinhVien sv1, SinhVien sv2)
{
	return strcmp(sv1.HoTen, sv2.HoTen);
}
/// hàm sắp xếp sinh viên
void SortAsc(SinhVien* arrSV, const int& n, SVComparer svc)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (svc(arrSV[i], arrSV[j]) > 0)
			{
				SinhVien svTemp = arrSV[i];
				arrSV[i] = arrSV[j];
				arrSV[j] = svTemp;
			}
		}
	}
}
/// có thể sử dụng con trỏ hàm không cần định nghĩa trước
void SortDesc(SinhVien* arrSV, const int& n, int (*svSoSanh)(SinhVien, SinhVien))
{
	/// sắp xếp giảm dần
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (svSoSanh(arrSV[i], arrSV[j]) < 0)
			{
				SinhVien svTemp = arrSV[i];
				arrSV[i] = arrSV[j];
				arrSV[j] = svTemp;
			}
		}
	}
}
int find_first_of(const char* s, char needle) {
	int length = strlen(s);
	for (int i = 0; i < length; i++) {
		if (s[i] == needle) {
			return i;
		}
	}
}
SinhVien* LoadSV(const char* path, int& n)
{
	n = 0;
	/// đọc danh sách sinh viên từ file
	/// trả về pointer trỏ đến mảng SinhVien đọc được
	/// n là số sinh viên đọc được
	
	ifstream reader(path, ios::in);
	char* buffer = new char[100];
	int count = 0;
	SinhVien* data = new SinhVien[MAXLEN];
	while (!reader.eof()) {
		reader.getline(buffer, 50, '\n');
		cout << buffer << endl;
		n++;
		size_t length = strlen(buffer);

		
		int needle = find_first_of(buffer, ';');
		int startPos = 0;
		char mssv[10];
		strncpy_s(mssv, buffer + startPos, needle);
		data[count].MSSV = atoi(mssv);

		char hoten[100];
		startPos = needle;
		strncpy_s(hoten, buffer + startPos + 1, length - startPos);
		strcpy_s(data[count].HoTen, hoten);
		count++; 
	}

	return data;
	reader.close();
}
int main()
{
	const char* path = "data.txt";
	int n = 0;
	SinhVien* arrSV1 = LoadSV(path, n);
	SinhVien* arrSV2 = LoadSV(path, n);
	cout << "***************Arr begin**************" << endl;
	PrintArr(arrSV1, n);
	SortAsc(arrSV1, n, SVC1);
	cout << "**********Arr sorted mode 1***********" << endl;
	PrintArr(arrSV1, n);
	SortDesc(arrSV2, n, SVC2);
	cout << "**********Arr sorted mode 2***********" << endl;
	PrintArr(arrSV2, n);
	system("pause");
}