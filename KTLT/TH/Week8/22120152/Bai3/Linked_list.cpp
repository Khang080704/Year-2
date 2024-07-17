#include"Linked_list.h"
Node* createNode(int data) {
    Node* p = new Node;
    if (p == NULL) {
        return NULL;
    }
    else {
        p->data = data;
        p->pNext = NULL;
    }
}
bool isEmpty(Linked_list list) {
    //Check if list is empty
    if (list.pHead == NULL && list.pTail == NULL) {
        return true;
    }
    else {
        return false;
    }
}
void addEmpty(Linked_list& list, int data) {
    Node* p = createNode(data);
    list.pHead = list.pTail = p;
}
void addLast(Linked_list& list, int data) {
    if (isEmpty(list)) {
        addEmpty(list, data);
    }
    else {
        Node* p = createNode(data);
        list.pTail->pNext = p;
        list.pTail = p;
    }
}
void addFirst(Linked_list& list, int data) {
    if (isEmpty(list)) {
        addEmpty(list, data);
    }
    else {
        Node* p = createNode(data);
        p->pNext = list.pHead;
        list.pHead = p;
    }
}
void printList(Linked_list list) {
    for (Node* i = list.pHead; i != NULL; i = i->pNext) {
        cout << i->data << " ";
    }
    cout << endl;
}
void removeTail(Linked_list& list) {
    if (list.pHead == list.pTail) {
        Node* p = list.pHead;
        list.pHead = list.pTail = NULL;
        delete p;
    }
    else {
        Node* cur = list.pHead;
        Node* after = cur->pNext;
        while (after != list.pTail) {
            cur = cur->pNext;
            after = cur->pNext;
        }
        list.pTail = cur;
        cur->pNext = NULL;

        delete after;
    } 
}
void removeHead(Linked_list& list) {
    if (list.pHead == list.pTail) {
        Node* p = list.pHead;
        list.pHead = list.pTail = NULL;
        delete p;
    } 
    else {
        Node* p = list.pHead;
        list.pHead = list.pHead->pNext;
        p->pNext = NULL;
        delete p;
    }
}