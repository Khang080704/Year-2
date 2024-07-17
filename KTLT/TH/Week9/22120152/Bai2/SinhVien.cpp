#include"SinhVien.h"
Node* createNode(SinhVien data) {
	Node* p = new Node;
	p->data = data;
	p->pNext = NULL;
	return p;
}
void initLinkedList(Linked_List& list) {
	list.head = list.tail = NULL;
}
bool isEmpty(Linked_List list) {
	return (list.head == NULL && list.tail == NULL);
}
void addEmpty(Linked_List& list, SinhVien value) {
	Node* p = createNode(value);
	list.head = list.tail = p;
}
void addLast(Linked_List& list, SinhVien value) {
	if (isEmpty(list)) {
		addEmpty(list, value);
	}
	else {
		Node* p = createNode(value);
		list.tail->pNext = p;
		list.tail = p;
	}
}
void printList(Linked_List list, void (*info)(SinhVien t)) {
	for (Node* i = list.head; i != NULL; i = i->pNext) {
		info(i->data);
	}
	cout << endl;
}

void nhapSinhVien(SinhVien& t) {
	cout << "Nhap ten: ";
	cin.getline(t.name, 30);
	cout << "Nhap ID: ";
	cin.getline(t.id, 30);
	cout << "Nhap diem: ";
	cin >> t.score;
	cin.ignore();
}
void removeByIndex(Linked_List& list, Node* t) {
	if (list.head == t && list.tail == t) {
		list.head = list.tail = NULL;
	}
	else {
		if (t == list.head) {
			removeHead(list);
		}
		else {
			Node* cur = list.head;
			Node* after = cur->pNext;
			while (after != t) {
				cur = cur->pNext;
				after = cur->pNext;
			}
			cur->pNext = after->pNext;
			after->pNext = NULL;
			delete after;
		}

	}

}
void removeHead(Linked_List& list) {
	if (list.head == list.tail) {
		list.head = list.tail = NULL;
	}
	else {
		Node* p = list.head;
		list.head = list.head->pNext;
		p->pNext = NULL;
		delete p;
	}

}
void XoaDanhSach(Linked_List& list) {
	while (!isEmpty(list)) {
		removeHead(list);
	}
}
void addByIndex(Linked_List& list, Node* index, Node* value) {
	if (list.head == index && list.tail == index)
	{
		list.tail->pNext = value;
		list.tail = value;
	}
	else {
		Node* cur = list.head;
		while (cur != index) {
			cur = cur->pNext;
		}
		value->pNext = cur->pNext;
		cur->pNext = value;
	}
}