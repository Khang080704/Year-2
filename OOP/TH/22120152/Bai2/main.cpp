#include<iostream>
#include"Stack.h"

using namespace std;

int main()
{
	Stack a;
	a.push("Pham");
	a.push("Gia");
	a.push("Khang");
	cout << a.top();
	return 0;
}