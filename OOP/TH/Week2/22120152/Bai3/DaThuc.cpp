#include "DaThuc.h"
DaThuc::DaThuc(int number) {
	data = new DonThuc[number];
	operandNumber = number;
}
DaThuc::DaThuc(const DaThuc& a) {
	int n = a.operandNumber;
	operandNumber = n;
	data = new DonThuc[n];
	for (int i = 0; i < n; i++) {
		data[i] = a.data[i];
	}
}
DaThuc::~DaThuc() {
	delete[] data;
	operandNumber = 0;
}
void DaThuc::input() {
	for (int i = 0; i < operandNumber; i++) {
		cin >> data[i];
	}
}
void DaThuc::output() {
	for (int i = 0; i < operandNumber; i++) {
		cout<< data[i];
	}
	std::cout << endl;
}
int DaThuc::calculate_value(int value) {
	int sum = 0;
	for (int i = 0; i < operandNumber; i++) {
		sum += data[i].Calculate_value(value);
	}
	return sum;
}
void DaThuc::erase(int index) {
	for (int i = index; i < operandNumber; i++) {
		data[i] = data[i + 1];
	}
	operandNumber--;
}
void DaThuc::stadardize() {
	for (int i = 0; i < operandNumber; i++) {
		for (int j = i + 1; j < operandNumber; j++) {
			if (data[i].getDegree() == data[j].getDegree()) {
				data[i] = data[i] + data[j];
				erase(j);
			}
		}
	}
}
void DaThuc::sortByDegree() {
	for (int i = 0; i < operandNumber - 1; i++) {
		for (int j = i + 1; j < operandNumber; j++) {
			if (data[i].getDegree() > data[j].getDegree()) {
				DonThuc temp = data[i];
				data[j] = data[i];
				data[i] = temp;
			}
		}
	}
}
DonThuc& DaThuc::operator[](int index) {
	return data[index];
}
int DaThuc::highestDegree() {
	int maxDegree = data[0].getDegree();
	for (int i = 0; i < operandNumber; i++) {
		if (maxDegree < data[i].getDegree()) {
			maxDegree = data[i].getDegree();
		}
	}
	return maxDegree;
}
DonThuc DaThuc::highestOperand() {
	for (int i = 0; i < operandNumber; i++) {
		if (data[i].getDegree() == highestDegree()) {
			return data[i];
		}
	}
}
DaThuc DaThuc::operator+(const DaThuc& a) {
	DaThuc temp = a;
	DaThuc result (this->operandNumber + a.operandNumber);
	int count = 0;
	for (int i = 0; i < this->operandNumber; i++) {
		bool isEqual = false;
		for (int j = 0; j < temp.operandNumber; j++) {
			if (data[i].getDegree() == temp.data[j].getDegree()) {
				result.data[count++] = data[i] + temp.data[j];
				isEqual = true;
				temp.erase(j);
				break;
			}
		}
		if (isEqual == false) {
			result.data[count++] = data[i];
		}
	}

	for (int i = 0; i < temp.operandNumber; i++) {
		result.data[count++] = temp[i];
	}
	result.operandNumber = count;

	return result;

}
DaThuc DaThuc::operator*(const DaThuc& a) {
	DaThuc result(this->operandNumber * a.operandNumber);
	int count = 0;
	for (int i = 0; i < this->operandNumber; i++) {
		for (int j = 0; j < a.operandNumber; j++) {
			result.data[count++] = data[i] * a.data[j];
		}
	}
	result.stadardize();
	return result;
}
DaThuc DaThuc::operator-(const DaThuc& a) {
	DaThuc temp = a;
	DaThuc result(this->operandNumber + a.operandNumber);
	int count = 0;
	for (int i = 0; i < this->operandNumber; i++) {
		bool isEqual = false;
		for (int j = 0; j < temp.operandNumber; j++) {
			if (data[i].getDegree() == temp.data[j].getDegree()) {
				result.data[count++] = data[i] - temp.data[j];
				isEqual = true;
				temp.erase(j);
				break;
			}
		}
		if (isEqual == false) {
			result.data[count++] = data[i];
		}
	}

	for (int i = 0; i < temp.operandNumber; i++) {
		result.data[count++] = temp[i];
	}
	result.operandNumber = count;

	return result;
}