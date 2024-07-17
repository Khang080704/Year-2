#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
#include<fstream>
using namespace std;
struct SinhVien {
	char name[30];
	char id[8];
	float score;
};
struct Node {
	SinhVien data;
	Node* pNext;
};
struct Linked_List {
	Node* head;
	Node* tail;
};
Node* createNode(SinhVien data);
void initLinkedList(Linked_List& list);
bool isEmpty(Linked_List list);
void addEmpty(Linked_List& list, SinhVien value);
void addLast(Linked_List& list, SinhVien value);
void removeHead(Linked_List& list);
void removeByIndex(Linked_List& list, Node* t);
void printList(Linked_List list, void (*info)(SinhVien t));
void nhapSinhVien(SinhVien& t);
void XoaDanhSach(Linked_List& list);
void addByIndex(Linked_List& list, Node* index, Node* value);