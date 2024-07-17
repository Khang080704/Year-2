#include "DonThuc.h"
DonThuc::DonThuc():coefficient(0),expoment(0) {
}
ostream& operator <<(ostream& output, DonThuc a) {
	if (a.expoment == 0) {
		cout << a.coefficient;
	}
	else {
		if (a.coefficient > 0) {
			cout << "+" << a.coefficient << "x^" << a.expoment;
		}
		else {
			cout << a.coefficient << "x^" << a.expoment;
		}
	}
	
	
	
	return output;
}
istream& operator >>(istream& input, DonThuc& a) {
	std::cout << "Nhap he so:"; 
	input >> a.coefficient;
	std::cout << "Nhap so mu: ";
	input >> a.expoment;
	return input;
}

int DonThuc::Calculate_value(int value) {
	return coefficient * pow(value, expoment);
}
DonThuc& DonThuc::operator +(DonThuc x) {
	if (this->expoment == x.expoment) {
		DonThuc result;
		result.coefficient = this->coefficient + x.coefficient;
		result.expoment = this->expoment;
		return result;
	}

	
}
DonThuc& DonThuc::operator -(DonThuc x) {
	if (this->expoment == x.expoment) {
		this->coefficient -= x.coefficient;
	}
	return *this;
}
DonThuc& DonThuc::operator *(DonThuc x) {
	DonThuc result;
	result.coefficient = this->coefficient * x.coefficient;
	result.expoment = this->expoment + x.expoment;
	return result;
}
int DonThuc::getDegree() {
	return expoment;
}
DonThuc& DonThuc::operator= (const DonThuc& x) {
	this->coefficient = x.coefficient;
	this->expoment = x.expoment;
	return *this;
}
void DonThuc::display() {
	if (coefficient > 0) {
		cout << " +" << coefficient << "x^" << expoment;
	}
	else {
		cout << coefficient << "x^" << expoment;
	}
}
bool DonThuc::operator==(const DonThuc& x) {
	if (this->coefficient == x.coefficient && this->expoment == x.expoment) {
		return true;
	}
	return false;
}
DonThuc& DonThuc::operator/(DonThuc x) {
	DonThuc result;
	result.coefficient = this->coefficient / x.coefficient;
	result.expoment = this->expoment - x.expoment;
	return result;
}