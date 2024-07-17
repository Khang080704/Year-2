#pragma once
#include<iostream>
using namespace std;
struct  Node
{
    int data;
    Node* pNext;
};
struct Linked_list {
    Node* pHead;
    Node* pTail;
    Linked_list() {
        pHead = pTail = NULL;
    }
};
Node* createNode(int data);
bool isEmpty(Linked_list list);
void addEmpty(Linked_list& list, int data);
void addLast(Linked_list& list, int data);
void addFirst(Linked_list& list, int data);
void printList(Linked_list list);
void removeTail(Linked_list& list);
void removeHead(Linked_list& list);