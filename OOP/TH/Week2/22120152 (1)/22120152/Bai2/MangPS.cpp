#include "MangPS.h"

MangPS::MangPS()
{
	data = NULL;
	size = 0;
}
MangPS::MangPS(const MangPS& p) {
	size = p.size;
	data = new PhanSo[size];
	for (int i = 0; i < size; i++) {
		data[i] = p.data[i];
	}
}
MangPS::MangPS(int size) {
	this->size = size;
	data = new PhanSo[this->size];
}
void MangPS::input(int n) {
	for (int i = 0; i < n; i++) {
		cin >> data[i];
	}
	size = n;
}
void MangPS::output() {
	for (int i = 0; i < size; i++) {
		cout << data[i];
	}
}
PhanSo MangPS::sumPS() {
	PhanSo sum;
	for (int i = 0; i < size; i++) {
		sum += data[i];
	}
	return sum;
}
void MangPS::sort() {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (data[i] < data[j]) {
				PhanSo temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
}

MangPS::~MangPS()
{
	delete[] data;
	this->size = 0;
}

