#include"darray.h"
int main()
{
	cout << "Nhap so phan tu cua mang: ";
	int n; cin >> n;
	darray a(n);
	for (int i = 0; i < n; i++) {
		cout << "Nhap gia tri: ";
		int x; cin >> x;
		a.push_back(x);
	}
	cout << "Mang vua nhap la: ";
	a.print();

	
	
	

	
	return 0;
}