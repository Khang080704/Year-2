#include<iostream>
using namespace std;
int Tinhxn(int n);
int Tinhyn(int n);


int Cau1(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n + Cau1(n - 1);
	}
}

float Cau2(int n) {
	if (n == 1) {
		return 1;
	}
	return  1.0 / n + Cau2(n - 1);
}

int Cau3(int n) {
	if (n == 1) {
		return 1;
	}
	return n * Cau3(n - 1);
}

int Cau4(int x, int n) {
	if (x == 0 && n != 0) {
		return 0;
	}
	if (x != 0 && n == 0) {
		return 1;
	}
	else {
		return x * Cau4(x, n - 1);
	}
}

int Cau5(int x, int n) {
	if (n == 1) {
		return Cau4(x, 2);
	}
	else {
		return Cau4(x, 2 * n) + Cau5(x, n - 1);
	}
}

int Cau6(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return Cau6(n - 1) + Cau6(n - 2);
	}

}

int Tinhxn(int n) {
	if (n == 0) {
		return 1;
	}
	return Tinhxn(n - 1) + Tinhyn(n - 1);
}
int Tinhyn(int n) {
	if (n == 0) {
		return 0;
	}
	return 3 * Tinhxn(n - 1) + 2 * Tinhyn(n - 1);
}

int Cau8(int n, int k) {
	if (k == 1) {
		return n;
	}
	if (n == k) {
		return 1;
	}
	if (1 < k && k < n) {
		return Cau8(n, k - 1) + Cau8(n - 1, k - 1);
	}
	
}

int main()
{
	//Cau 1
	cout << "Cau 1: Tinh tong 1+2+...+n: " << endl;
	cout << "Nhap n: ";
	int cau1; cin >> cau1;
	cout << "Tong 1+2+...+" << cau1 << "= " << Cau1(cau1) << endl << endl;

	//Cau 2
	cout << "Cau 2: Tinh tong 1 + 1/2 + ... + 1/n" << endl;
	cout << "Nhap n: ";
	int cau2; cin >> cau2;
	cout << "Tong 1 + 1/2 + ... + 1/" << cau2 << "= " << Cau2(cau2) << endl << endl;

	//Cau 3
	cout << "Cau 3: Tinh n!" << endl;
	cout << "Nhap n: ";
	int cau_3; cin >> cau_3;
	cout << cau_3 << "! = " << Cau3(cau_3) << endl << endl;

	//Cau 4
	cout << "Cau 4: Tinh x^n" << endl;
	cout << "Nhap x: ";
	int x_cau4; cin >> x_cau4;
	cout << "Nhap n: ";
	int n_cau4; cin >> n_cau4;
	cout << x_cau4 << "^" << n_cau4 << "= " << Cau4(x_cau4, n_cau4) << endl << endl;

	//Cau 5
	cout << "Cau 5: Tinh x^2 + x^4 + ... + x^2n" << endl;
	cout << "Nhap x: ";
	int x_cau5; cin >> x_cau5;
	cout << "Nhap n: ";
	int n_cau5; cin >> n_cau5;
	cout << x_cau5 << "^2 + " << x_cau5 << "^4 + ... + " << x_cau5 << "^" <<2* n_cau5 << "= " << Cau5(x_cau5, n_cau5) << endl << endl;
	

	//Cau6
	cout << "Tinh so fibonacci thu n" << endl;
	cout << "Nhap vao n: ";
	int n_cau6; cin >> n_cau6;
	cout << "So fibonacci thu " << n_cau6 << ": " << Cau6(n_cau6) << endl << endl;

	//Cau 7
	cout << "Tinh x(n), y(n)" << endl;
	cout << "Nhap vao n: ";
	int n_cau7; cin >> n_cau7;
	cout << "x(" << n_cau7 << ") = " << Tinhxn(n_cau7) << endl;
	cout << "y(" << n_cau7 << ") = " << Tinhyn(n_cau7) << endl << endl;

	//Cau8
	cout << "Tinh to hop chap k cua n phan tu: ";
	cout << "Nhap k: ";
	int k_cau8; cin >> k_cau8;
	cout << "Nhap n: ";
	int n_cau8; cin >> n_cau8;
	cout << "C(" << n_cau8 << "," << k_cau8 << ") = " << Cau8(n_cau8, k_cau8) << endl;
}