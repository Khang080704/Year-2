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
int soLuong(Linked_List list);

void initList(Linked_List& list, int n) {
	for (int i = 1; i <= n; i++) {
		int x = rand() % (2000 + 1000) - 1000;
		ThemPhanTuVaoCuoiDanhSach(list, x);
	}
}
void sort(Linked_List& list) {
	for (Node* i = list.Head; i != NULL; i = i->pNext) {
		for (Node* j = i->pNext; j != NULL; j = j->pNext) {
			if (i->data > j->data) {
				int temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}
Linked_List mergeList(Linked_List list1, Linked_List list2) {
	Linked_List result;
	KhoiTao(result);
	for (Node* i = list1.Head; i != NULL; i = i->pNext) {
		ThemPhanTuVaoCuoiDanhSach(result,i->data);
	}
	for (Node* i = list2.Head; i != NULL; i = i->pNext) {
		ThemPhanTuVaoCuoiDanhSach(result, i->data);
	}
	sort(result);
	return result;
}


int main() {
	srand(time(0));
	Linked_List list1;
	KhoiTao(list1);
	Linked_List list2;
	KhoiTao(list2);
	int n = rand() % (20 - 5) + 5;
	initList(list1, n);
	n = rand() % (20 - 5) + 5;
	initList(list2, n);
	sort(list1);
	sort(list2);
	DuyetDanhSach(list1);
	cout << endl;
	DuyetDanhSach(list2);
	Linked_List result = mergeList(list1, list2);
	DuyetDanhSach(result);
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

int soLuong(Linked_List list) {
	int count = 0;

	for (Node* p = list.Head; p != NULL; p = p->pNext) {
		count++;
	}

	return count;
}






