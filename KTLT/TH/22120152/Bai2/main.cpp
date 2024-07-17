#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
const int BIT = 8;

void decimal_to_binary(int n) {
	vector<int> result;
	for (int i = 0; i < BIT; i++) {
		int temp = n;
		int a = (temp >> i) & 1;
		result.push_back(a);
	}

	reverse(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
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

int main()
{
	int n; cin >> n;
	decimal_to_binary(n);
}