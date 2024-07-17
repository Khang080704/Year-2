#include "PhanSo.h"

PhanSo::PhanSo()
{
	tuSo = 0;
	mauSo = 1;
}
PhanSo::PhanSo(int a, int b) {
	tuSo = a;
	mauSo = b;
}
PhanSo::PhanSo(const PhanSo& p) {
	tuSo = p.tuSo;
	mauSo = p.mauSo;
}


PhanSo& PhanSo::operator+(PhanSo a) {
	/*this->tuSo = this->tuSo * a.mauSo + a.tuSo * this->mauSo;
	this->mauSo = a.mauSo * this->mauSo;
	return *this;*/
	PhanSo c;
	c.tuSo = this->tuSo * a.mauSo + a.tuSo * this->mauSo;
	c.mauSo = a.mauSo * this->mauSo;
	return c;
}
PhanSo& PhanSo::operator-(PhanSo a) {
	this->tuSo = this->tuSo * a.mauSo - a.tuSo * this->mauSo;
	this->mauSo = a.mauSo * this->mauSo;
	return *this;
}
PhanSo& PhanSo::operator*(PhanSo a) {
	this->tuSo = this->tuSo * a.tuSo;
	this->mauSo = a.mauSo * this->mauSo;
	return *this;
}
PhanSo& PhanSo::operator/(PhanSo a) {
	this->tuSo = this->tuSo * a.mauSo;
	this->mauSo = a.tuSo * this->mauSo;
	return *this;
}
PhanSo& PhanSo::operator+=(PhanSo a) {
	this->tuSo = this->tuSo * a.mauSo + a.tuSo * this->mauSo;
	this->mauSo = a.mauSo * this->mauSo;
	return *this;
}
bool PhanSo::operator>(PhanSo a) {
	return (this->tuSo * a.mauSo > a.tuSo * this->mauSo);
}
bool PhanSo::operator<(PhanSo a) {
	return (this->tuSo * a.mauSo < a.tuSo * this->mauSo);
}
bool PhanSo::operator==(PhanSo a) {
	return (this->tuSo * a.mauSo == a.tuSo * this->mauSo);
}
bool PhanSo::operator>=(PhanSo a) {
	return ((this->tuSo * a.mauSo > a.tuSo * this->mauSo) || 
		(this->tuSo * a.mauSo == a.tuSo * this->mauSo));
}
bool PhanSo::operator<=(PhanSo a) {
	return ((this->tuSo * a.mauSo < a.tuSo * this->mauSo) ||
		(this->tuSo * a.mauSo == a.tuSo * this->mauSo));
}
