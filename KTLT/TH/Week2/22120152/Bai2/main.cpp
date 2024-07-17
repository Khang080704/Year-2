#include<iostream>
using namespace std;
const int LOW = -1000;
const int UP = 2000;

bool isPrime(int);
bool isSquare(int);
void printArray(int*, int);

void initArray(int*& a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (UP - LOW) + LOW;
	}
}

int findFirstSquare(int* a, int n) {
	for (int i = 0; i < n; i++) {
		if (isSquare(a[i])) {
			return a[i];
		}
	}
	return -1;
}

void findSubPrime(int* a, int n) {
	int* b = new int[n];
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (isPrime(a[i])) {
			b[count++] = a[i];
		}
	}

	if (count == 0) {
		cout << "Mang khong co so nguyen to" << endl;
	}
	else {
		cout << "Mang con chua so nguyen to la: ";
		printArray(b, count);
	}


	delete[] b;
}

int main()
{
	srand(time(NULL));
	int n = 0;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	int* a = new int[n];
	initArray(a, n);
	cout << "Mang duoc phat sinh: ";
	printArray(a, n);

	int firstSquare = findFirstSquare(a, n);
	if (firstSquare == -1) {
		cout << "Mang khong co so chinh phuong" << endl;
	}
	else {
		cout << "So chinh phuong dau tien trong mang: " << firstSquare << endl;
	}
	cout << endl;
	findSubPrime(a, n);

	delete[] a;
}
bool isPrime(int a) {
	if (a < 0) return false;
	for (int i = 2; i < a - 1; i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}
bool isSquare(int a) {
	if (a < 0) return false;
	for (int i = 1; i <= sqrt(a); i++) {
		if (i * i == a) {
			return true;
		}
	}
	return false;
}
void printArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}