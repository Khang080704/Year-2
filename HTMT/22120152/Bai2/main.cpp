#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

vector<int> addSubBinartyWithCarry(vector<int> a, vector<int> b);
vector<int> substractBinaryWithBorrow(vector<int> a, vector<int> b);
vector<int> multiple(vector<int> m, vector<int> q);
vector<int> toOneComplement(vector<int> a);
vector<int> toTwoComplement(vector<int> a);
unsigned int binaryToUnsignedInt(vector<int>& binary);
int binaryToSignedInt(vector<int>& binary);
void shiftRight(vector<int>& a);
void shiftLeft(vector<int>& a);
void printVector(vector<int> a);


void halfAdd(vector<int>& a, vector<int>& b, vector<int> total) {
	for (int i = 0; i < total.size() / 2; i++) {
		a[i] = total[i];
	}

	int index = 0;
	for (int i = total.size() / 2; i < total.size(); i++) {
		b[index++] = total[i];
	}
}
vector<int> multiple(vector<int> m, vector<int> q) {
	int n = q.size();
	int temp = n;
	vector<int> C(1, 0);
	vector<int> A(n, 0);
	vector<int> C_A(n + 1, 0);
	vector<int> C_A_Q(2 * n + 1, 0);

	for (int i = 2 * n + 1 - 1; i >= n + 1; i--) {
		C_A_Q[i] = q[temp - 1];
		temp--;
	}

	int k = n;
	while (k > 0) {
		if (C_A_Q[C_A_Q.size() - 1] == 1) {
			C_A = addSubBinartyWithCarry(C_A, m);
			for (int i = 0; i < C_A_Q.size() - n; i++) {
				C_A_Q[i] = C_A[i];
			}
		}
		shiftRight(C_A_Q);
		shiftRight(C_A);
		k--;
	}
	return C_A_Q;
}

vector<int> changeStringToVector(string n) {
	vector<int> result(n.size(), 0);

	for (int i = 0; i < n.size(); i++) {
		result[n.size() - 1 - i] = (int)n[n.size() - i - 1] - 48;
	}
	return result;
}


void divide(vector<int> Q, vector<int> M) {
	int n = Q.size();
	int k = n;
	vector<int> A(n);
	vector<int> A_Q(2 * n, 0);
	if (binaryToSignedInt(Q) > 0) {
		for (int i = 0; i < n; i++) {
			A[i] = 0;
		}
	}
	else {
		if (binaryToSignedInt(Q) < 0) {
			for (int i = 0; i < n; i++) {
				A[i] = 1;
			}
		}
		else {
			cout << "Thuong: " << endl;
			printVector(Q);
			cout << endl;
			cout << "So du: " << endl;
			printVector(A);
			return;
		}
		
	}

	
	for (int i = 0; i < n; i++) {
		A_Q[i] = A[i];
	}
	int index = 0;
	for (int i = n; i < 2 * n; i++) {
		A_Q[i] = Q[index++];
	}


	while (k > 0) {
		shiftLeft(A_Q);
		halfAdd(A, Q, A_Q);

		//A - M -> A
		vector<int> result = substractBinaryWithBorrow(A, M);
		int index = result.size() - 1;
		for (int i = A.size() - 1; i >= 0; i--) {
			A[i] = result[index--];
		}

		if (binaryToSignedInt(A) < 0) {
			A_Q[A_Q.size() - 1] = 0;
			vector<int> result = addSubBinartyWithCarry(A, M);
			int x = result.size() - 1;
			for (int i = A.size() - 1; i >= 0; i--) {
				A[i] = result[x--];
			}


		}
		else {
			A_Q[A_Q.size() - 1] = 1;
			Q[Q.size() - 1] = 1;
			for (int i = 0; i < n ; i++) {
				A_Q[i] = A[i];
			}

		}
		k--;
	}
	cout << "Thuong: " << endl;
	printVector(Q);
	cout << endl;
	cout << "So du: " << endl;
	printVector(A);
}

int main()
{

	string a, b;
	cout << "Nhap chuoi nhi phan thu nhat: "; cin >> a;
	cout << "Nhap chuoi nhi phan thu hai: "; cin >> b;
	vector<int> x = changeStringToVector(a);
	vector<int> y = changeStringToVector(b);
	cout << "Nhap phep tinh: ";
	char op;
	cin >> op;
	switch (op)
	{
	case'+': {
		vector<int> result = addSubBinartyWithCarry(x, y);
		printVector(result);
		break;
	}
	case'-': {
		vector<int> result = substractBinaryWithBorrow(x, y);
		printVector(result);
		break;
	}
	case'*': {
		vector<int> result = multiple(x, y);
		printVector(result);
		break;
	}
	case'/': {
		divide(x, y);
		break;
	}

	default:
		break;
	}


}

vector<int> addSubBinartyWithCarry(vector<int> a, vector<int> b) {
	
		vector<int> result;
		int carry = 0;

		int i = a.size() - 1;
		int j = b.size() - 1;

		while (i >= 0 || j >= 0 || carry > 0) {
			int sum = carry;

			if (i >= 0)
				sum += a[i--];
			if (j >= 0)
				sum += b[j--];

			result.insert(result.begin(), sum % 2);
			carry = sum / 2;
		}

		return result;
	
	
}

vector<int> substractBinaryWithBorrow(vector<int> a, vector<int> b) {
	return addSubBinartyWithCarry(a, toTwoComplement(b));
}

void shiftRight(vector<int>& a) {
	for (int i = a.size() - 1; i > 0; i--) {
		a[i] = a[i - 1];
	}
	a[0] = 0;
}

void shiftLeft(vector<int>& a) {
	for (int i = 0; i < a.size() - 1; i++) {
		a[i] = a[i + 1];
	}
	a[a.size() - 1] = 0;
}

void printVector(vector<int> a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}
}
vector<int> toOneComplement(vector<int> a) {
	vector<int> result = a;
	for (int i = 0; i < result.size(); i++) {
		if (result[i] == 0) {
			result[i] = 1;
		}
		else {
			result[i] = 0;
		}
	}
	return result;
}

vector<int> toTwoComplement(vector<int> a) {
	vector<int> sub = toOneComplement(a);
	vector<int> one(a.size(), 0);
	one[one.size() - 1] = 1;
	return addSubBinartyWithCarry(sub, one);
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