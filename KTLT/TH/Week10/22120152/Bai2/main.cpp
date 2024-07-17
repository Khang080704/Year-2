#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

bool isPalindrome(int l, int r, char* s) {
	if (r == 1) {
		return true;
	}
	if ((l + r) % 2 == 1) {
		int mid = (l + r) / 2;
		if (l == mid - 1 && r - 1 == mid + 1 && s[l] == s[r - 1]) {
			return true;
		}
		else {
			if (s[l] != s[r - 1]) {
				return false;
			}
			return isPalindrome(l + 1, r - 1, s);
		}
	}
	else {
		int mid = (l + r) / 2;
		if (r - 1 == mid && l == mid - 1 && s[l] == s[r - 1]) {
			return true;
		}
		else {
			if (s[l] != s[r - 1]) {
				return false;
			}
			return isPalindrome(l + 1, r - 1, s);
		}
	}
}



int main()
{
	char* a = new char[100];
	char b[100];
	cout << "Nhap vao 1 chuoi: ";
	cin.getline(b, 100);
	strcpy(a, b);
	if (isPalindrome(0, strlen(a), a)) {
		cout << a << " la chuoi doi xung" << endl;
	}
	else {
		cout << a << " khong la chuoi doi xung" << endl;
	}
	delete[] a;
}