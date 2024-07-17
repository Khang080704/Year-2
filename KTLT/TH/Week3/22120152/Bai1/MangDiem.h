#pragma once
#ifndef _MANGDIEM_H_
#define _MANGDIEM_H_
#include "Diem.h"
Diem* NhapMangDiem(int& n);
void xuatMangDiem(Diem* a, int n);
Diem TimXaNhat(Diem* a, int n, Diem A);
void LietKeToaDoDuong(Diem* a, int n);
void SapTangTheoKhoangCach(Diem* a, int n);
#endif
