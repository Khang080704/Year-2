#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node* pNext;
};

struct Linked_List {
	Node* Head;
	Node* Tail;
};
void KhoiTao(Linked_List& list);
Node* KhoiTaoNode(int x);
void ThemPhanTuVaoCuoiDanhSach(Linked_List& list, int x);
void DuyetDanhSach(Linked_List list);
void initList(Linked_List& list, int n) {
	for (int i = 1; i <= n; i++) {
		int x = rand() % (50 + 50) - 50;
		ThemPhanTuVaoCuoiDanhSach(list, x);
	}
}
void divide(Linked_List source, Linked_List& less, Linked_List& greate, int x) {
	for (Node* i = source.Head; i != NULL; i = i->pNext) {
		if (i->data < x) {
			ThemPhanTuVaoCuoiDanhSach(less, i->data);
		}
		else {
			ThemPhanTuVaoCuoiDanhSach(greate, i->data);
		}
	}
}

int main()
{
	srand(time(NULL));
	Linked_List list;
	KhoiTao(list);
	int n = rand() % (100 - 10) + 10;
	int x = rand() % (10 + 10) - 10;
	initList(list, n);
	cout << "Danh sach ban dau: ";
	DuyetDanhSach(list);

	Linked_List lessThanx;
	Linked_List greateThanx;
	KhoiTao(lessThanx);
	KhoiTao(greateThanx);
	cout << "So duoc phat sinh: ";
	cout << x << endl;
	divide(list, lessThanx, greateThanx, x);
	cout << "Danh sach nho hon " << x << " :";
	DuyetDanhSach(lessThanx);
	cout << "Danh sach lon hon " << x << " :";
	DuyetDanhSach(greateThanx);
	


	return 0;
}
void KhoiTao(Linked_List& list) {
	list.Head = NULL;
	list.Tail = NULL;
}
Node* KhoiTaoNode(int x) {
	Node* p = new Node;
	if (p == NULL) cout << "Khong du bo nho de cap phat" << endl;
	else {
		p->data = x;
		p->pNext = NULL;
	}

	return p;
}

void ThemPhanTuVaoCuoiDanhSach(Linked_List& list, int x) {
	Node* p = KhoiTaoNode(x);
	if (list.Head == NULL) list.Head = list.Tail = p;
	else {
		list.Tail->pNext = p;
		list.Tail = p;
	}
}

void DuyetDanhSach(Linked_List list) {
	for (Node* k = list.Head; k != NULL; k = k->pNext) {
		cout << k->data << " ";
	}

	cout << endl;
}
