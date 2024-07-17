#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
int stack1[1000], stack2[1000], stack3[1000], stack0[1000];
void chuyendia(int a, int b, int c, int n, int& sp)
{
	sp++;
	stack0[sp] = n - 1; stack1[sp] = c; stack2[sp] = b; stack3[sp] = a;
	sp++;
	stack0[sp] = 1; stack1[sp] = a; stack2[sp] = b; stack3[sp] = c;
	sp++;
	stack0[sp] = n - 1; stack1[sp] = a; stack2[sp] = c; stack3[sp] = b;
}
void HNtower(int a, int b, int c, int n)
{
	stack0[0] = n; stack1[0] = a; stack2[0] = b; stack3[0] = c;
	int sp = 0;
	while (sp >= 0)
	{
		sp--;
		if (stack0[sp + 1] == 1) {

			cout << "Chuyen 1 dia tu cot " << (char)stack1[sp + 1] << " sang cot " <<(char) stack2[sp + 1] << endl;
		}
		else {
			chuyendia(stack1[sp + 1], stack2[sp + 1], stack3[sp + 1], stack0[sp + 1], sp);
		}
			
	}
}
int main()
{
	
	int n;
	cout << "nhap so dia: ";
	cin >> n;
	HNtower('A', 'B', 'C', n);
}