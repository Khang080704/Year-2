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

LinkedList* CreateLinkedList() {
    LinkedList* list = new LinkedList;
    if (list != NULL) {
        list->pHead = list->pTail = NULL;
    }
    return list;
}

bool AddNode(LinkedList* list, const int& value) {
    Node* p = CreateNode(value);
    if (p == NULL) {
        return false;
    }

    if (list->pHead == NULL) {
        list->pHead = list->pTail = p;
        return true;
    }

    list->pTail->pNext = p;
    list->pTail = p;

    return true;
}

bool InsertNode(LinkedList* list, Node* node, const int& value) {
    Node* p = CreateNode(value);
    if (p == NULL) {
        return false;
    }

    Node* temp = NULL;
    for (temp = list->pHead; temp != NULL; temp = temp->pNext) {
        if (temp == node) {
            break;
        }
    }

    if (temp == NULL) {
        return false;
    }

    p->pNext = node->pNext;
    node->pNext = p;

    return true;

}

int DeleteNode(LinkedList* list, const int& value) {
    int sl = 0;

    Node* currentNode = list->pHead;

    //ktra node dau tien co phai la node can xoa
    while (currentNode != NULL && currentNode->data == value) {
        list->pHead = currentNode->pNext;

        if (currentNode == list->pTail) {
            list->pTail = currentNode->pNext;
        }

        delete currentNode;
        sl++;
        currentNode = list->pHead;
    }

    for (Node* p = currentNode->pNext; p != NULL; p = p->pNext) {
        if (p->data == value) {
            Node* pTemp = p;

            currentNode->pNext = p->pNext;
            p = currentNode;
            delete pTemp;
            sl++;
        }
        else {
            currentNode = p;
        }
    }

    return sl;
}
//Ham xoa danh sach lien ket
void DeleteLinkedList(LinkedList* dslk) {
    Node* p = dslk->pHead;
    while (p != NULL)
    {
        dslk->pHead = p->pNext;
        delete p;
        p = dslk->pHead;
    }
    delete dslk;
}
//Ham phat sinh danh sach lien ket
LinkedList* GenerateLinkedList(const int& slMin, const int& slMax, const int& gtMin, const int& gtMax) {
    LinkedList* dslk = CreateLinkedList();
    if (dslk == NULL) {
        return NULL;
    }
    int sl = slMin + rand() % (slMax - slMin + 1);
    for (int i = 0; i < sl; i++) {
        AddNode(dslk, gtMin + rand() % (gtMax - gtMin + 1));
    }
    return dslk;
}
int findMax(LinkedList* list) {
    int max = list->pHead->data;
    for (Node* i = list->pHead; i != NULL; i = i->pNext) {
        if (max < i->data) {
            max = i->data;
        }
    }
    return max;
}
int findMin(LinkedList* list) {
    int min = list->pHead->data;
    for (Node* i = list->pHead; i != NULL; i = i->pNext) {
        if (min > i->data) {
            min = i->data;
        }
    }
    return min;
}
int sum(LinkedList* list) {
    int sum = 0;
    for (Node* i = list->pHead; i != NULL; i = i->pNext) {
        sum += i->data;
    }
    return sum;
}
int countMax(LinkedList* list) {
    int max = findMax(list);
    int count = 0;
    for (Node* i = list->pHead; i != NULL; i = i->pNext) {
        if (max == i->data) {
            count++;
        }
    }
    return count;
}
void print(LinkedList* list) {
    for (Node* i = list->pHead; i != NULL; i = i->pNext) {
        cout << i->data << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));
    int slMin = 5;
    int slMax = 20;
    int gtMin = 10;
    int gtMax = 20;
    LinkedList* list = GenerateLinkedList(slMin, slMax, gtMin, gtMax);
    print(list);
    cout << "Phan tu lon nhat: "<<findMax(list) << endl;
    cout << "Phan tu nho nhat: " << findMin(list) << endl;
    cout << "Tong: "<<sum(list) << endl;
    cout << "So luong phan tu lon nhat: "<<countMax(list);
}