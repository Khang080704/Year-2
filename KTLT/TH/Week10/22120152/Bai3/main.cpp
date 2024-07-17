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
		while (l != mid - 1 && r - 1 != mid + 1) {
			if (s[l] != s[r - 1]) {
				return false;
			}
			else {
				l++;
				r--;
			}
		}
		if (s[l] == s[r - 1]) {
			return true;
		}
		return false;
		
	}
	else {
		int mid = (l + r) / 2;
		while (r - 1 != mid && l != mid - 1) {
			if (s[l] != s[r - 1]) {
				return false;
			}
			else {
				l++;
				r--;
			}
		}
		if (s[l] == s[r - 1]) {
			return true;
		}
		return false;
		
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