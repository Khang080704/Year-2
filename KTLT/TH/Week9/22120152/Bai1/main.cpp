#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* pNext;
};
Node* createNode(int data) {
	Node* p = new Node;
	p->data = data;
	p->pNext = NULL;
	return p;
}
struct Linked_List {
	Node* head;
	Node* tail;
};
void initLinkedList(Linked_List& list) {
	list.head = list.tail = NULL;
}
bool isEmpty(Linked_List list) {
	return (list.head == NULL && list.tail == NULL);
}
void addEmpty(Linked_List& list, int value) {
	Node* p = createNode(value);
	list.head = list.tail = p;
}
void addLast(Linked_List& list, int value) {
	if (isEmpty(list)) {
		addEmpty(list, value);
	}
	else {
		Node* p = createNode(value);
		list.tail->pNext = p;
		list.tail = p;
	}
}
void generateLinkedList(Linked_List& list, int slMin, int slMax, int gtMin, int gtMax) {
	int n = rand() % (slMax - slMin) + slMin;
	for (int i = 1; i <= n; i++) {
		int value = rand() % (gtMax - gtMin) + gtMin;
		addLast(list, value);
	}
}
void printList(Linked_List list) {
	for (Node* i = list.head; i != NULL; i = i->pNext) {
		cout << i->data << " ";
	}
	cout << endl;
}
int countElement(Linked_List list) {
	int count = 0;
	for (Node* i = list.head; i != NULL; i = i->pNext) {
		count++;
	}
	return count;
}
void divideHalf(Linked_List list, Linked_List& first, Linked_List& second) {
	int count = countElement(list);
	Node* p = list.head;
	
		for (int i = 1; i <= count / 2; i++) {
			addLast(first, p->data);
			p = p->pNext;
		}
		for (int i = count / 2 + 1; i <= count; i++) {
			addLast(second, p->data);
			p = p->pNext;
		}
}
void divideOnPointer(Linked_List list, Linked_List& first, Linked_List& second, Node* point) {
	Node* p = list.head;
	while (p != point) {
		p = p->pNext;
	}
	for (Node* i = list.head; i != p; i = i->pNext) {
		addLast(first, i->data);
	}
	for (Node* i = p; i != NULL; i = i->pNext) {
		addLast(second, i->data);
	}
}
Node* getNodeFromValue(Linked_List list, int value) {
	for (Node* i = list.head; i != NULL; i = i->pNext) {
		if (i->data == value) {
			return i;
		}
	}
	return NULL;
}
int main() {
	srand(time(NULL));
	Linked_List list;
	initLinkedList(list);
	generateLinkedList(list, 5, 20, 0, 100);
	printList(list);
	Linked_List first, second;
	initLinkedList(first);
	initLinkedList(second);
	int x; 
	cout << "Nhap vao gia tri: ";
	cin >> x;
	Node* p = getNodeFromValue(list, x);
	if (p != NULL) {
		divideOnPointer(list, first, second, p);
		cout << "Danh sach duoc chia theo " << x << endl;
		cout << "Nua dau danh sach: ";
		printList(first);
		cout << "Nua sau danh sach: ";
		printList(second);
	}
	
	
}