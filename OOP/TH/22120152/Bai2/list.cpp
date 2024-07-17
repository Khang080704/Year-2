#include "list.h"
Node* List::makeNode(const string& val) {
	Node* newNode = new Node;
	newNode->next = NULL;
	newNode->data = val;
	return newNode;
}

List::List() {
	Head = NULL;
	count = 0;
}

List::~List() {
	/*for (Node* i = Head; i != NULL; i = i->next) {
		delete i;
	}*/
}

void List::insert(int pos, const string& val) {
	//Node* pTruoc = new Node;
	//Node* pSau = pTruoc->next;
	assert(pos >= 0 && pos <= count);
	Node* newNode = makeNode(val);

	if (pos == 0) {
		newNode->next = Head;
		Head = newNode;
	}
	else {

		Node* prev = Head;
		for (int i = 0; i < pos - 1; ++i) {
			prev = prev->next;
		}
		newNode->next = prev->next;
		prev->next = newNode;
	}
	count++;
}

void List::erase(int pos) {
	assert(pos >= 0 && pos < count);
	if (pos == 0) {
		Node* temp = Head;
		Head = Head->next;
		delete temp;
	}
	else {

		Node* prev = Head;
		for (int i = 0; i < pos - 1; ++i) {
			prev = prev->next;
		}
		Node* temp = prev->next;
		prev->next = temp->next;
		delete temp;
	}

	count--;

}

string List::get(int pos) const {
	assert(pos >= 0 && pos < count);

	Node* current = Head;
	for (int i = 0; i < pos; ++i) {
		current = current->next;
	}
	return current->data;
}

void List::print() const {
	for (Node* i = Head; i != NULL; i = i->next) {
		cout << i->data << " ";
	}
}

int List::size() const {
	return count;
}