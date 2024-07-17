// Bai3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"DaThuc.h"

int main()
{
    cout << "Nhap so luong phan tu da thuc 1: ";
    int number = 0; cin >> number;
    DaThuc a(number);
    a.input();
    a.stadardize();
    cout << "Da thuc a: ";
    a.output();
    
    cout << "Nhap so luong phan tu da thuc 2: ";
    int n = 0; cin >> n;
    DaThuc b(n);
    b.input();
    b.stadardize();
    cout << "Da thuc b: ";
    b.output();


    //Ham stadardize() de rut gon da thuc co cung so mu
    DaThuc cong = a + b;
    cong.stadardize();
    cout << "a + b = ";
    cong.output();

    DaThuc tru = a - b;
    tru.stadardize();
    cout << "a - b = ";
    tru.output();

    DaThuc nhan = a * b;
    nhan.stadardize();
    cout << "a * b = ";
    nhan.output();
    

    
}

