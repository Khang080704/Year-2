#include<iostream>
using namespace std;

void move(char A, char B) {
	cout << "Chuyen 1 dia tu cot " << A << " sang cot " << B << endl;
}

void HNtower(int n, char src, char mid, char des) {
	if (n == 1) {
		move(src, des);
	}
	else {
		HNtower(n - 1, src, des, mid);
		move(src, des);
		HNtower(n - 1, mid, src, des);
	}
}


int main()
{
	cout << "Nhap vao so luong dia: ";
	int n; cin >> n;
	HNtower(n, 'A', 'B', 'C');

}