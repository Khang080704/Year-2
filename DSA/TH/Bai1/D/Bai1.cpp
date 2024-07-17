#include<iostream>
#include<string>
using namespace std;

struct SV {
	int id;
	char ten[30];
	char gioiTinh[5];
	int tuoi;
	float diemToan;
	float diemLy;
	float diemHoa;
	float diemTB = 0;
	char hocluc[10];
};

struct Node {
	SV data;
	struct Node* pNext;
};
struct Linked_List {
	Node* Head;
	Node* Tail;
};
void KhoiTao(Linked_List& list);
Node* KhoiTaoNode(SV x);
void ThemPhanTuVaoCuoiDanhSach(Linked_List& list, SV x);
void DuyetDanhSach(Linked_List list);
void Del_First(Linked_List& list);
void Del_Last(Linked_List& list);
void Del(Linked_List& list, Node* p);

void nhap(SV& a) {
	cout << "Nhap ten: ";
	cin.getline(a.ten, 30);
	cout << "Gioi tinh: ";
	cin.getline(a.gioiTinh, 5);
	cout << "ID: ";
	cin >> a.id;
	cin.ignore();
	cout << "Tuoi: ";
	cin >> a.tuoi;
	cout << "Diem 3 mon: ";
	cin >> a.diemToan >> a.diemLy >> a.diemHoa;

	a.diemTB = 1.0 * (a.diemToan + a.diemLy + a.diemHoa) / 3;
	if (a.diemTB < 5) {
		a.hocluc[0] = 'K';
		a.hocluc[1] = 'e';
		a.hocluc[2] = 'm';
	}
	else {
		if (a.diemTB <= 6) {
			a.hocluc[0] = 'T';
			a.hocluc[1] = 'B';
		}
		else {
			if (a.diemTB <= 8) {
				a.hocluc[0] = 'K';
				a.hocluc[1] = 'h';
				a.hocluc[2] = 'a';
			}
			else {
				a.hocluc[0] = 'G';
				a.hocluc[1] = 'i';
				a.hocluc[2] = 'o';
				a.hocluc[3] = 'i';
			}
		}
	}
}

void xuat(SV a) {
	cout << a.ten << endl;
	cout << a.tuoi << endl;
	cout << a.gioiTinh << endl;
	cout << a.id << endl;
	cout << a.diemToan << endl;
	cout << a.diemLy << endl;
	cout << a.diemHoa << endl;
	cout << a.diemTB << endl;

	if (a.diemTB > 8) {
		for (int i = 0; i < 4; i++) {
			cout << a.hocluc[i];
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			cout << a.hocluc[i];
		}
	}

}

void DeleteByID(Linked_List& list, int id) {
	for (Node* k = list.Head; k != NULL; k = k->pNext) {
		if (id == k->data.id) {
			Del(list, k);
		}
	}
}

void findByName(Linked_List list, string name) {
	for (Node* i = list.Head; i != NULL; i = i->pNext) {
		if (i->data.ten == name) {
			xuat(i->data);
		}
	}
}

void sortByName(Linked_List& list) {
	for (Node* i = list.Head; i != NULL; i = i->pNext) {
		for (Node* k = i->pNext; k != NULL; k = k->pNext) {
			if (i->data.ten > k->data.ten) {
				Node* temp = i;
				i = k;
				k = temp;
			}
		}
	}
}

void sortByGPA(Linked_List& list) {
	for (Node* i = list.Head; i != NULL; i = i->pNext) {
		for (Node* j = i->pNext; j != NULL; j = j->pNext) {
			if (i->data.diemTB < j->data.diemTB) {
				Node* temp = i;
				i = j;
				j = temp;
			}
		}
	}
}



int main()
{
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	SV* a = new SV[n];
	Linked_List list;
	KhoiTao(list);

	for (int i = 0; i < n; i++) {
		nhap(a[i]);
		ThemPhanTuVaoCuoiDanhSach(list, a[i]);
	}

	int id;
	cin >> id;
	DeleteByID(list, id);
	DuyetDanhSach(list);
	cout << endl;

	sortByName(list);
	DuyetDanhSach(list);
	cout << endl;

	sortByGPA(list);
	DuyetDanhSach(list);
	cout << endl;

	delete[] a;
}

void KhoiTao(Linked_List& list) {
	list.Head = NULL;
	list.Tail = NULL;
}
Node* KhoiTaoNode(SV x) {
	Node* p = new Node;
	if (p == NULL) cout << "Khong du bo nho de cap phat" << endl;
	else {
		p->data = x;
		p->pNext = NULL;
	}

	return p;
}

void ThemPhanTuVaoCuoiDanhSach(Linked_List& list, SV x) {
	Node* p = KhoiTaoNode(x);
	if (list.Head == NULL) list.Head = list.Tail = p;
	else {
		list.Tail->pNext = p;
		list.Tail = p;
	}
}

void DuyetDanhSach(Linked_List list) {
	for (Node* k = list.Head; k != NULL; k = k->pNext) {
		xuat(k->data);
	}

	cout << endl;
}

void Del_First(Linked_List& list) {
	Node* p = list.Head;
	p = p->pNext;
	list.Head = p;
}

void Del_Last(Linked_List& list) {
	Node* pTruoc = list.Head;
	Node* pSau = pTruoc->pNext;

	while (pSau->pNext != NULL) {
		pTruoc = pSau;
		pSau = pSau->pNext;
	}
	pTruoc->pNext = NULL;
	list.Tail = pTruoc;

}

void Del(Linked_List& list, Node* p) {
	if (p == list.Head) {
		Del_First(list);
	}
	else {
		if (p == list.Tail) {
			Del_Last(list);
		}
		else {
			Node* pTruoc = list.Head;
			Node* pSau = pTruoc->pNext;

			while (pSau != NULL) {
				if (pSau == p) {
					pTruoc->pNext = pSau->pNext;
					pSau->pNext = NULL;
					break;
				}
				else {
					pTruoc = pTruoc->pNext;
					pSau = pTruoc->pNext;
				}
			}
		}
	}
}
