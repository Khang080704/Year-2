// Bai2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<sstream>

using namespace std;

string shiftLeft(string s) {
    stringstream ss(s);
    string result = "";
    string buffer;
    while (ss >> buffer) {
        result += buffer;
    }
    return result;
}

void forceFloat(float* p, string s) {
    unsigned int* ptr = (unsigned int*)(p);
    *ptr &= 0;
    int len = 0;
    
    for (int i = 0; i < s.length() && i < 32; i++) {
        if (s[i] == '1') {
            *ptr |= (1 << (31 - i));
        }
    }

}

int main()
{
    float x = 1;
    string s = "0 00000000 00000000000000000000001";
    cout << s << " chuyen sang so thuc: ";
    string binary = shiftLeft(s);
    forceFloat(&x, binary);
    cout << x;
}