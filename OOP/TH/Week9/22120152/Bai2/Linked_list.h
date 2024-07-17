#pragma once
#include<iostream>
using namespace std;
template<typename T>
class Node {
public:
	T data;
	Node* pNext;
	Node() {
		data = 0;
		pNext = NULL;
	}
	Node(T value) {
		data = value;
		pNext = NULL;
	}
};
template<typename T>
class Linked_list
{
private:
	Node<T>* head;
	Node<T>* tail;
	int count;
public:
	Linked_list() {
		head = tail = NULL;
		count = 0;
	}
	Linked_list(int n) {
		count = n;
	}
	bool isEmpty() {
		if (head == NULL && tail == NULL) {
			return true;
		}
		return false;
	}
	void addEmty(T value) {
		Node<T>* p = new Node<T>(value);
		head = tail = p;
		count++;
	}
	void addLast(T value) {
		if (isEmpty()) {
			addEmty(value);
		}
		else {
			Node<T>* p = new Node<T>(value);
			tail->pNext = p;
			tail = p;
			count++;
		}
		
	}
	void printList() {
		for (Node<T>* i = head; i != NULL; i = i->pNext) {
			std::cout << i->data << " ";
		}
	}
	~Linked_list()
	{
		Node<T>* temp = head;
		while (temp) {
			Node<T>* nextNode = temp->pNext;
			delete temp;
			temp = nextNode;
		}
	}
	int size() const {
		return count;
	}
	T operator[](int pos) {
		Node<T>* p = head;
		for (int i = 0; i < pos; i++) {
			p = p->pNext;
		}
		return p->data;
	}
};

