// Bai4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    //Chuyen doi float -> int -> float
    /*float x = 3.9;
    cout << x << " (float) " << endl;
    int y = static_cast<int>(x);
    cout << y << " (int) " << endl;
    float z = static_cast<float>(y);
    cout << z <<" (float) " << endl << endl;*/

    ////Chuyen doi int -> float -> int
    //int a = 4;
    //cout << a << " (int) " << endl;
    //float b = static_cast<float>(a);
    //cout << b << " (float) " << endl;
    //int c = static_cast<int>(b);
    //cout << c << " (int) " << endl;

    ////Kiem tra ket hop
    //float first, second, third;
    //first = 1.2;
    //second = 1.4;
    //third = 1.5;
    //if ((first + second) + third == first + (second + third)) {
    //    cout << "Co tinh ket hop" << endl;
    //}
    //else {
    //    cout << "Khong co tinh ket hop" << endl;
    //}
    //cout << endl;

    //Voi i la bien kieu int, f la bien kieu float
    int i;
    float f = 1.2;

    i = (int)(3.14159 * f);
    f = f + (float)i;
    if (i == (int)((float)i)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    if (i == (int)((double)i)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    if (f == (float)((int)f)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    if (f == (double)((int)f)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
}

