#include<iostream>
#include<vector>
using namespace std;

void initRandom(int**& a, int row, int collum, int low, int up);
void print2DArray(int** a, int row, int collum);
void findValue(int** a, int row, int collum, int value) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < collum; j++) {
			if (a[i][j] == value) {
				cout << value << " nam o toa do (" << i << "," << j << ")";
				return;
			}
		}
	}
	cout << "Khong tim thay gia tri";
	return;
}

int sumInBorder(int** a, int row, int collum) {
	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < collum; j++) {
			if (i == 0 || i == row - 1 || j == 0 || j == collum - 1) {
				sum += a[i][j];
			}
		}
	}
	return sum;
}
//Ham dich xoay mang 1 chieu sang phai
void rotateRight(int*& a, int n ) {
	int temp = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		a[i + 1] = a[i];
	}
	a[0] = temp;
}
void rotateRightMatrix(int**& a, int row, int collum, int k) {
	//Ham nay de dich xoay vong cot sang phai k lan
	k = k % collum;
	for (int i = 0; i < row; i++) {
		for (int j = 1; j <= k; j++) {
			rotateRight(a[i], collum);
		}
	}
}

//Ham tim ma tran chuyen vi
void tranposeMatrix(int**& a, int row, int collum) {
	//Tao 1 ma tran co kich thuoc nguoc lai voi ma tran ban dau
	int** temp = new int* [collum];
	for (int i = 0; i < collum; i++) {
		temp[i] = new int[row];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < collum; j++) {
			temp[j][i] = a[i][j];
		}
	}

	print2DArray(temp,collum,row);

	for (int i = 0; i < collum; i++) {
		delete[] temp[i];
	}
}

bool isSubMatrix(int** a, int row, int collum, int** subMatrix, int subRow, int subCollum) {
	for (int i = 0; i <= row - subRow; ++i) {
		for (int j = 0; j <= collum - subCollum; ++j) {
			bool isMatch = true;
			for (int r = 0; r < subRow; ++r) {
				for (int c = 0; c < subCollum; ++c) {
					if (a[i + r][j + c] != subMatrix[r][c]) {
						isMatch = false;
						break;
					}
				}
				if (!isMatch) break;
			}
			if (isMatch) return true;
		}
	}
	return false;
}

int main()
{
	srand(time(NULL));
	int row = 0;
	cout << "Nhap so hang: ";
	cin >> row;

	int collum = 0;
	cout << "Nhap so cot: ";
	cin >> collum;

	int low = 0, up = 0;
	cout << "Nhap khoang sinh so: "; cin >> low >> up;

	int** a = new int* [row];

	for (int i = 0; i < row; i++) {
		a[i] = new int[collum];
	}

	initRandom(a, row, collum, low, up);
	cout << "Ma tran: " << endl;
	print2DArray(a, row, collum);
	cout << endl;
	//Chuyen vi ma tran
	cout << "Ma tran sau khi chuyen vi la: " << endl;
	tranposeMatrix(a, row, collum);
	cout << endl;

	//Dich xoay ma tran
	cout << "Nhap so dong can dich xoay: ";
	int k = 0; cin >> k;
	rotateRightMatrix(a, row, collum, k);
	cout << "Ma tran sau khi dich xoay cot sang phai " << k << " lan: " << endl;
	print2DArray(a, row, collum);

	//Tim kiem phan tu
	cout << "Nhap gia tri can tim kiem: ";
	int key = 0; cin >> key;
	findValue(a, row, collum, key);
	cout << endl;

	//Tinh tong phan tu o bien
	cout << "Tong cac phan tu o bien la: " << sumInBorder(a, row, collum) << endl << endl;

	//Kiem tra ma tran con
	cout << "Nhap dong cot cua ma tran con: ";
	int subRow = 0, subCollum = 0;
	cin >> subRow >> subCollum;
	int** subMaxtrix = new int* [subRow];
	for (int i = 0; i < row; i++) {
		subMaxtrix[i] = new int[subCollum];
	}
	cout << "Nhap phan tu: " << endl;
	for (int i = 0; i < subRow; i++) {
		for (int j = 0; j < subCollum; j++) {
			cin >> subMaxtrix[i][j];
		}
	}

	if (isSubMatrix(a, row, collum, subMaxtrix, subRow, subCollum)) {
		cout << "Ma tran con co ton tai trong ma tran " << endl;
	}
	else {
		cout << "Ma tran con khong ton tai trong ma tran " << endl;
	}



	//Free memory
	for (int i = 0; i < row; i++) {
		delete[] a[i];
	}
	for (int i = 0; i < row; i++) {
		delete[] subMaxtrix[i];
	}
}

void initRandom(int**& a, int row, int collum, int low, int up) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < collum; j++) {
			a[i][j] = rand() % (up - low) + low;
		}
	}
}
void print2DArray(int** a, int row, int collum) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < collum; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}