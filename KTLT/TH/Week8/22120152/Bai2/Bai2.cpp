#include <iostream>
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
void sortList(Linked_list& list) {
    for (Node* i = list.pHead; i != NULL; i = i->pNext) {
        for (Node* j = i->pNext; j != NULL; j = j->pNext) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


int main()
{
    cout << "Nhap so luong phan tu: ";
    Linked_list list;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Nhap phan tu thu " << i << " : ";
        int x; cin >> x;
        addLast(list, x);
    }
    cout << "Danh sach da nhap: ";
    printList(list);
    sortList(list);
    cout << "Danh sach sau khi sap xep: ";
    printList(list);
}


