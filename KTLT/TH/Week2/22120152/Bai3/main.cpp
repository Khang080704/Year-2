#include<iostream>
using namespace std;
const int LOW = -50;
const int UP = 50;

void initArray(int*& a, int n);
void printArray(int* a, int n);

void findAppearOnly(int* p, int n, int* q, int m) {
	int* temp = new int[n];
	int subCount = 0;
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < m; j++) {
			if (p[i] == q[j]) {
				count++;
			}
		}
		if (count == 0) {
			temp[subCount++] = p[i];
		}
	}
	printArray(temp, subCount);

	delete[] temp;
}

void combine(int* p, int n, int* q, int m) {
	findAppearOnly(p, n, q, m);
	findAppearOnly(q, m, p, n);
}

int main()
{
	srand(time(NULL));
	int n = 0;
	cout << "Nhap so luong phan tu mang thu nhat: ";
	cin >> n;
	int m = 0;
	cout << "Nhap so luong phan tu mang thu hai: ";
	cin >> m;

	int* p = new int[n];
	int* q = new int[m];
	initArray(p, n);
	initArray(q, m);
	printArray(p, n);
	printArray(q, m);

	cout << "Nhung phan tu xuat hien trong p ma khong xuat hien trong q la: ";
	findAppearOnly(p, n, q, m);

	cout << "Nhung phan tu khac nhau doi mot la: " << endl;
	combine(p, n, q, m);

	delete[] p;
	delete[] q;
}

void initArray(int*& a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (UP - LOW) + LOW;
	}
}
void printArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}