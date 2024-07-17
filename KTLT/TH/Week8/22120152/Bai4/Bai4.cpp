#include "Linked_list.h"
struct Queue {
    int size;
    int maxSize;
    Linked_list list;
};
void initQueue(Queue& q, int n) {
    q.size = 0;
    q.maxSize = n;
    q.list.pHead = q.list.pTail = NULL;
}
bool isEmpty(Queue q) {
    if (q.size == 0) {
        return true;
    }
    return false;
}
bool isFull(Queue q) {
    if (q.size == q.maxSize) {
        return true;
    }
    return false;
}
void push(Queue& q, int data) {
    if (isFull(q)) {
        cout << "Queue da day khong the them" << endl;
        return;
    }
    addLast(q.list, data);
    q.size++;
}
int Front(Queue q) {
    return q.list.pHead->data;
}
void pop(Queue& q) {
    if (isEmpty(q)) {
        cout << "Queue rong khong the xoa" << endl;
        return;
    }
    removeHead(q.list);
    q.size--;
}
void printQueue(Queue q) {
    printList(q.list);
}
void clear(Queue& q) {
    while (!isEmpty(q))
    {
        pop(q);
    }
}

int main()
{
    Queue q;
    initQueue(q, 100);
    cout << "Nhap so luong phan tu them vao queue: ";
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Nhap phan tu thu " << i << " : ";
        int x; cin >> x;
        push(q, x);
    }
    cout << "Queue da them vao la: " << endl;
    printQueue(q);
    clear(q);
    printQueue(q);
}


