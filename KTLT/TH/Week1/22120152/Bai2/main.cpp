#include<iostream>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
const int bit = 8;

void decimal_to_binary(int n) {
	vector<int> result;
	for (int i = 0; i < bit; i++) {
		int temp = n;
		int a = (temp >> i) & 1;
		result.push_back(a);
	}

	reverse(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
}

int decimal_to_hexa_table(int n) {
	switch (n)
	{
	case 10: return 'A'; break;
	case 11: return 'B'; break;
	case 12: return 'C'; break;
	case 13: return 'D'; break;
	case 14: return 'E'; break;
	case 15: return 'F'; break;
	default:
		return n + 48;
		break;
	}
}
void decimal_to_hexa(int n) {
	int temp = n;
	vector<int>result;
	while (temp != 0) {
		int remain = temp % 16;
		result.push_back(decimal_to_hexa_table(remain));
		temp = temp / 16;
	}
	reverse(result.begin(), result.end());


	for (int i = 0; i < result.size(); i++) {
		cout << (char)result[i];
	}
}

int hexa_to_decimal_table(char a) {
	switch (a)
	{
	case 'A':return 10; break;
	case 'B':return 11; break;
	case 'C':return 12; break;
	case 'D':return 13; break;
	case 'E':return 14; break;
	case 'F':return 15; break;
	default:
		return a - 48;
		break;
	}
}
int hexa_to_decimal(string n) {
	size_t exp = n.size() - 1;
	int result = 0;
	for (int i = 0; i < n.size(); i++) {
		result += hexa_to_decimal_table(n[i]) * pow(16, exp);
		exp--;
	}
	return result;
}

int binary_to_decimal(string n) {
	int result = 0;
	size_t exp = n.size() - 1;
	for (int i = 0; i < n.size(); i++) {
		if (n[i] == '1') {
			result += (n[i] - 48) * pow(2, exp);
		}
		exp--;
	}
	return result;
}

int main()
{
	cout << "Chuong trinh chuyen doi giua cac he co so: " << endl;
	cout << "1. Chuyen doi tu he 10 ve he 2" << endl;
	cout << "2. Chuyen doi tu he 10 ve he 16" << endl;
	cout << "3. Chuyen doi tu he 16 ve he 10" << endl;
	cout << "4. Chuyen doi tu he 2 ve he 10" << endl;
	cout << "5. Ket thuc chuong trinh" << endl;
	int choose = 0;
	cout << endl;
	do {
		cout << "Vui long chon chuc nang: ";
		cin >> choose;
		switch (choose)
		{
		case 1: { //
			cout << "Nhap so nguyen n o he 10: ";
			int n; cin >> n;
			cout << n << " he 10 chuyen sang he nhi phan la: ";
			decimal_to_binary(n);
			cout << endl;
			break;
		}
		case 2: {
			cout << "Nhap so nguyen n o he 10: ";
			int n; cin >> n;
			cout << n << " he 10 chuyen sang he 16 la: ";
			decimal_to_hexa(n);
			cout << endl;
			break;
		}
		case 3: {
			cout << "Nhap so nguyen n o he 16: ";
			string n; cin >> n;
			int result = hexa_to_decimal(n);
			cout << n << " he 16 chuyen sang he 10 la: " << result;
			cout << endl;
			break;
		}
		case 4: {
			cout << "Nhap so nguyen n o he 2: ";
			string n; cin >> n;
			int result = binary_to_decimal(n);
			cout << n << " he 2 chuyen sang he 10 la: " << result;
			cout << endl;
			break;
		}
		default:
			cout << "Chuong trinh ket thuc!";
			break;
		}
	} while (choose != 5);

}