#include <iostream>
#include<string>
using namespace std;


void dumbFloat(float* p) {
    float value = *p;
    unsigned int* ptr = reinterpret_cast<unsigned int*>(&value);
    string dauLuong = "";
    string expoment = "";
    string dinhTri = "";

    dauLuong += to_string((*ptr >> 31) & 1);

    for (int i = 30; i >= 23; i--) {
        if ((*ptr >> i) & 1 == 1) {
            expoment += "1";
        }
        else {
            expoment += "0";
        }
    }
    for (int i = 22; i >= 0; i--) {
        if ((*ptr >> i) & 1 == 1) {
            dinhTri += "1";
        }
        else {
            dinhTri += "0";
        }
    }
    cout << dauLuong << " " << expoment << " " << dinhTri << endl;
    
}

int main() {
    cout << "Nhap vao so thuc: ";
    float num = 0;
    cin >> num;
    
    cout << num << " chuyen sang kieu nhi phan la: ";
    dumbFloat(&num);
 
}
