#include<iostream>
#include<map>
using namespace std;

void initRandom(int*& a, int n, int low, int up) {
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (up - low) + low;
	}
}

int findMax(map<int, int> a) {
	int max = a.begin()->second;

	for (map<int, int>::iterator i = a.begin(); i != a.end(); i++) {
		if (max < i->second) {
			max = i->second;
		}
	}
	return max;
}

void sumMostAppear(int* a, int n) {
	map<int, int> countAppear;
	for (int i = 0; i < n; i++) {
		countAppear[a[i]]++;
	}

	for (map<int, int>::iterator i = countAppear.begin(); i != countAppear.end(); i++) {
		cout << i->first << " xuat hien " << i->second << " lan" << endl;
	}

	int sum = 0;
	int max = findMax(countAppear);
	for (map<int, int>::iterator i = countAppear.begin(); i != countAppear.end(); i++) {
		if (i->second == max) {
			sum += i->first;
		}
	}

	cout << "Tong phan tu co so lan xuat hien nhieu nhat la: " << sum;

}
void inputArray(int*& a, int& n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void outputArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void randomArray(int* a, int n, int low, int up) {
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (up - low) + low;
	}
}

int findMaxInArray(int* a, int n) {
	int max = a[0];

	for (int i = 0; i < n; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}

	return max;
}

int findMin(int* a, int n) {
	int min = a[0];

	for (int i = 0; i < n; i++) {
		if (min > a[i]) {
			min = a[i];
		}
	}

	return min;
}

int sumArray(int* a, int n) {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	return sum;
}

void sort(int* a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}

	}
}

double findMedian(int* a, int n) {
	sort(a, n);
	if (n % 2 == 1) {
		return 1.0 * a[n / 2];
	}
	else {
		return 1.0 / 2 * (a[n / 2] + a[n / 2 + 1]);
	}
}

bool isAppear(int* a, int n, int* b, int m) {
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j] == b[i]) {
				count++;
				break;
			}
		}
	}
	if (count == m) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	cout << "Nhap so nguyen n: ";
	int n; cin >> n;
	srand(time(NULL));
	int* a = new int[n];

	cout << "Nhap khoang sinh so ngau nhien ";
	int low; cin >> low;
	int up; cin >> up;
	randomArray(a, n, low, up);

	cout << "Mang duoc phat sinh ngau nhien la: ";
	outputArray(a, n);
	cout << endl;

	cout << "Phan tu trung vi la: ";
	cout << findMedian(a, n);
	cout << endl;

	cout << "Phan tu lon nhat: " << findMaxInArray(a, n) << ". Nho nhat: " << findMin(a, n);
	cout << endl;

	cout << "Tong phan tu trong mang: " << sumArray(a, n) << endl;
	sumMostAppear(a, n);
	cout << endl;

	cout << "Nhap so phan tu mang b:";
	int m; cin >> m;
	int* b = new int[m];
	cout << "Nhap phan tu: ";
	inputArray(b, m);

	if (isAppear(a, n, b, m)) {
		cout << "Mang b co xuat hien trong mang a";
	}
	else {
		cout << "Mang b khong xuat hien trong mang a";
	}

	delete[] b;
	delete[] a;
}