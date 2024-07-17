#include"Linked_list.h"
struct Stack {
    int size;
    int maxSize;
    Linked_list list;
};
void initStack(Stack& s, int n) {
    s.size = 0;
    s.maxSize = n;
    s.list.pHead = s.list.pTail = NULL;
}
bool isEmpty(Stack s) {
    if (s.size == 0) {
        return true;
    }
    return false;
}
bool isFull(Stack s) {
    if (s.size == s.maxSize) {
        return true;
    }
    return false;
}
void Push(Stack& s, int data) {
    addFirst(s.list, data);
    s.size++;
}
void Pop(Stack& s) {
    removeHead(s.list);
    s.size--;
}
int Top(Stack s) {
    return s.list.pHead->data;
}
void clear(Stack& s) {
    while (!isEmpty(s))
    {
        Pop(s);
    }
}
void printStack(Stack s) {
    printList(s.list);
}

int main()
{
    Stack s;
    initStack(s, 100);
    cout << "Nhap so luong phan tu them vao stack: ";
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Nhap phan tu thu " << i << " : ";
        int x; cin >> x;
        Push(s, x);
    }
    cout << "Stack da them vao la: " << endl;
    printStack(s);
}
