#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* pNext;
};

struct LinkedList {
    Node* pHead;
    Node* pTail;
};

Node* CreateNode(const int& value) {
    Node* p = new Node;
    if (p != NULL) {
        p->data = value;
        p->pNext = NULL;
    }
    return p;
}

void CreateLinkedList(LinkedList& list) {

    list.pHead = list.pTail = NULL;

}
// ham tim node dau tien trong dslk cho truoc co du lieu cho truoc
Node* GetNodePointer(LinkedList list, int value) {
    Node* p = list.pHead;
    bool flag = false;

    for (p; p != NULL; p = p->pNext) {
        if (p->data == value) {
            flag = true;
            return p;
        }
    }
    if (flag == false) {
        return NULL;
    }
}

// ham tim node co chi so (bat dau tu 0) cho truoc
Node* GetNodePointerData(LinkedList* list, int index) {
    int i = 0;
    Node* p = list->pHead;

    while (p != NULL && i < index) {
        p = p->pNext;
        ++i;
    }
    return p;
}

//ham xac dinh vi tri cua mot node cho truoc trong dslk cho truoc
int GetNodeIndex(LinkedList* list, Node* pNode) {
    if (list->pHead == NULL) {
        return -1;
    }
    Node* p = list->pHead;
    int i = 0;

    while (p != NULL) {
        if (p == pNode) {
            return i;
        }
        p = p->pNext;
        ++i;
    }

    return -1;
}

//ham xac dinh con tro den node dung truoc cua mot node cho truoc
Node* GetPreviousNodePointer(LinkedList list, Node* pNode) {
    Node* currentNode = list.pHead;
    Node* previousNode = NULL;
    while (currentNode != NULL) {
        if (currentNode == pNode) {
            return previousNode;
        }
        previousNode = currentNode;
        currentNode = currentNode->pNext;
    }
    return NULL;
}

// ham chen mot node cho truoc vao dau DSLK
bool KiemTraDanhSachRong(LinkedList list) {
    bool flag = false;
    if (list.pHead == NULL && list.pTail == NULL) {
        return flag = true;
    }
    return flag;
}

void ThemVaoRong(LinkedList list, Node* p) {

    list.pHead = list.pTail = p;

}

void AddHead(LinkedList& list, Node* p) {
    if (KiemTraDanhSachRong(list)) {
        ThemVaoRong(list, p);
    }

    p->pNext = list.pHead;
    list.pHead = p;
}

// chen mot node co du lieu cho truoc vao dau Dslk
Node* AddHeadInfo(LinkedList& list, int value) {
    Node* newNode = CreateNode(value);

    AddHead(list, newNode);
    return newNode;
}

// ham chen mot node cho truoc vao cuoi dslk
void AddTail(LinkedList& list, Node* pNewNode) {
    if (list.pTail == NULL) {
        list.pHead = pNewNode;
        list.pTail = pNewNode;
        pNewNode->pNext = NULL;
    }
    else {
        list.pTail->pNext = pNewNode;
        list.pTail = pNewNode;
    }
}

//ham chen mot nod co du lieu cho truoc vao cuoi dslk
Node* AddTailInfo(LinkedList& list, int value) {
    Node* p = CreateNode(value);
    if (p != NULL) {
        AddTail(list, p);
    }
    return p;
}

// ham chen mot node cho truoc vao sau mot node khac cho truoc
void AddAfter(LinkedList& list, Node* q, Node* afterNode) {
    Node* currentNode = list.pHead;
    if (currentNode == NULL || q == NULL) {
        return;
    }
    while (currentNode != NULL) {
        if (currentNode == q) {
            break;
        }
        currentNode = currentNode->pNext;
    }
    if (currentNode == NULL) {
        return;
    }
    afterNode->pNext = currentNode->pNext;
    currentNode->pNext = afterNode;

    if (currentNode == NULL) {
        list.pTail = afterNode;
    }
}

// ham chen vao mot node co du lieu cho truoc vao sau mot node khac cho truoc
Node* AddAfterInfo(LinkedList& list, Node* q, int info) {
    if (q == NULL) {
        return NULL;
    }
    Node* p = CreateNode(info);
    if (p != NULL) {
        AddAfter(list, q, p);
    }
    if (q->pNext != p) {
        return NULL;
    }
    return p;
}

// ham chen mot node cho truoc vao mot node khac cho truoc
void AddBefore(LinkedList& list, Node* q, Node* pNewNode) {
    if (q == NULL || pNewNode == NULL) {
        return;
    }
    if (q == list.pHead) {
        pNewNode->pNext = list.pHead;
        list.pHead = pNewNode;
        return;
    }
    Node* p = GetPreviousNodePointer(list, q);
    if (p == NULL) {
        return;
    }
    p->pNext = pNewNode;
    pNewNode->pNext = q;
}

// co info
Node* AddBeforeInfo(LinkedList& list, Node* q, int info) {
    if (q == NULL) {
        return NULL;
    }
    Node* p = CreateNode(info);
    if (p != NULL) {
        AddBefore(list, q, p);
        if (p->pNext != q) {
            return NULL;
        }
    }
    return p;
}

int CompareData(int a, int b) {
    if (a == b) {
        return 1;
    }
    return -1;
}
//ham chen dslk truoc sao cho dslk truoc van tang dan
void AddAscendingList(LinkedList& list, Node* pNewNode) {
    if (pNewNode == NULL) {
        return;
    }
    Node* p = list.pHead;
    while (p != NULL) {
        if (CompareData(p->data, pNewNode->data) > -1) {
            AddBefore(list, p, pNewNode);
            return;

        }
        p = p->pNext;
    }
    if (p == NULL && list.pTail != NULL) {
        list.pTail->pNext = pNewNode;
        list.pTail = pNewNode;
    }
}

// co info
Node* AddAscendingListInfo(LinkedList& list, int info) {
    Node* p = CreateNode(info);
    if (p != NULL) {
        AddAscendingList(list, p);
    }
    return p;

}

int RemoveHead(LinkedList& list) {
    int kq = INT_MIN;
    if (list.pHead == NULL) {
        return kq;
    }
    Node* p = list.pHead;
    list.pHead = list.pHead->pNext;
    if (list.pHead == NULL) {
        list.pTail = NULL;
    }
    kq = p->data;
    delete p;
    return kq;
}

int RemoveTail(LinkedList& list) {
    int kq = INT_MIN;
    if (list.pTail == NULL) {
        return kq;
    }
    Node* p = GetPreviousNodePointer(list, list.pTail);
    
    kq = list.pTail->data;
    list.pTail = p;
    Node* q = list.pTail->pNext;
    list.pTail->pNext = NULL;
    delete q;
    
    if (p == NULL) {
        list.pHead = p;
    }
    
    return kq;
}

int RemoveAfter(LinkedList& list, Node* q) {
    if (q == NULL) {
        return RemoveHead(list);
    }
    int kq;
    Node* p = list.pHead;
    while (p != NULL) {
        if (p == q) {
            break;
        }
        p = p->pNext;
    }
    if (p != NULL) {
        p = q->pNext;
        if (p != NULL) {
            p = q->pNext;
            if (p != NULL) {
                q->pNext = p->pNext;
                kq = p->data;
                delete p;
                if (q->pNext == NULL) {
                    list.pTail = q;
                }
            }
        }
    }
    return kq;
}

bool RemoveNode(LinkedList& list, int info) {
    Node* p = GetNodePointer(list, info);
    if (p == NULL) {
        return false;
    }
    Node* q = GetPreviousNodePointer(list, p);
    if (q == NULL) {
        list.pHead = p->pNext;
        delete p;
        if (list.pHead == NULL) {
            list.pTail = list.pHead;
        }
        return true;
    }
    q->pNext = p->pNext;
    delete p;
    if (q->pNext == NULL) {
        list.pTail = q;
    }
    return true;
}

void DuyetDanhSach(LinkedList list) {
    for (Node* k = list.pHead; k != NULL; k = k->pNext) {
        cout << k->data << " ";
    }

    cout << endl;
}
//Ham phat sinh danh sach lien ket
LinkedList GenerateLinkedList(const int& slMin, const int& slMax, const int& gtMin, const int& gtMax) {
    LinkedList dslk;
    CreateLinkedList(dslk);
    int sl = slMin + rand() % (slMax - slMin + 1);
    for (int i = 0; i < sl; i++) {
        AddTail(dslk, CreateNode(gtMin + rand() % (gtMax - gtMin + 1)));
    }
    return dslk;
}

int main()
{
    LinkedList list;
    srand(time(NULL));
    list = GenerateLinkedList(5, 20, 0, 100);
    cout << "Danh sach phat sinh ban dau: ";
    DuyetDanhSach(list);
    
    cout << "Danh sach sau khi xoa node dau: ";
    int head = RemoveHead(list);
    DuyetDanhSach(list);
    
    cout << "Danh sach sau khi xoa node cuoi ";
    int tail = RemoveTail(list);
    DuyetDanhSach(list);
    
    cout << "Danh sach sau khi them node vao cuoi: ";
    AddTail(list, CreateNode(rand()));
    DuyetDanhSach(list);
    
    cout << "Danh sach sau khi them node vao node thu 3: ";
    AddAfter(list, list.pHead->pNext->pNext, CreateNode(20));
    DuyetDanhSach(list);
    
    cout << "Danh sach sau khi them node vao dau: ";
    AddHead(list, CreateNode(rand()));
    DuyetDanhSach(list);

    Node* p = CreateNode(rand());
    AddAscendingList(list, p);
    cout << "Danh sach sau khi them node " << p->data << ": ";
    DuyetDanhSach(list);

    int value = rand();
    RemoveNode(list, value);
    cout << "Danh sach sau xoa " << value << ": ";
    DuyetDanhSach(list);

    return 0;
}
