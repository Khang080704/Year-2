#include<iostream>
#include"Stack.h"
using namespace std;

int main()
{
	Stack a(10); //Khoi tao stack voi 10 phan tu
	a.push(3);
	a.push(5);
	cout << a.pop();
}