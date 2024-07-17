#include "QLSinhVien.h"


QLSinhVien::~QLSinhVien() {
	delete[] data;
	number = 0;
}
QLSinhVien::QLSinhVien() {
	number = 0;
	data = new SinhVien[100];
}
void QLSinhVien::add(SinhVien a) {
	data[number] = a;
	number++;
}
int QLSinhVien::size() {
	return number;
}
void QLSinhVien::findUnderAverage() {
	double sum = 0.0;
	for (int i = 0; i < number; i++) {
		sum += data[i].average();
	}
	double finalAverage = sum / number;

	for (int i = 0; i < number; i++) {
		if (data[i].average() < finalAverage) {
			data[i].showInFile();
		}	
	}
}
void QLSinhVien::display() {
	for (int i = 0; i < number; i++) {
		data[i].show();
		cout << endl;
	}
}
bool QLSinhVien::isEmpty() {
	if (number == 0) {
		return true;
	}
	else {
		return false;
	}
}
void QLSinhVien::xepLoai() {
	for (int i = 0; i < number; i++) {
		data[i].ranking();
	}
}
