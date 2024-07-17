#include<iostream>
#include<vector>
using namespace std;
const int BIT = 32;

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

unsigned int binaryToUnsignedInt(vector<int>& binary) {
	unsigned int result = 0;
	for (int bit : binary) {
		result = (result << 1) | bit;
	}
	return result;
}

int binaryToSignedInt(vector<int>& binary) {
	int sign = binary[0];
	unsigned int unsignedValue = binaryToUnsignedInt(binary);

	if (sign == 1) {
		unsignedValue = ~unsignedValue + 1;
	}

	return unsignedValue;
}


int main()
{
	int n; 
	cout << "Nhap so nguyen n: ";
	cin >> n;
	cout << n << " chuyen sang he nhi phan la: ";
	decimal_to_binary(n);
	cout << endl;
	cout << endl;
	vector<int> a = { 0,0,0,0,0,0,0,0,
					 0,0,0,0,1,1,0,0,
					 0,0,0,0,1,0,0,0 };
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}
	cout << endl;
	cout <<"Mang a chuyen sang so nguyen la: " << binaryToSignedInt(a);
}