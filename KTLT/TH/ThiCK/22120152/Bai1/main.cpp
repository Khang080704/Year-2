#include<iostream>
#include<fstream>
using namespace std;
struct sinhvien {
	char hoTen[31];
	char maSo[9];
	double diem;
};
void inSinhVien(sinhvien a) {
	cout << a.hoTen << "(" << a.maSo << "); ";
}
struct GheNgoi {
	sinhvien data;
	int hang;
	int cot;
};
struct Node {
	GheNgoi data;
	Node* pNext;
};
struct ListGheNgoi {
	Node* head;
	Node* tail;
};
void xuatGheNgoi(GheNgoi a) {
	inSinhVien(a.data);
	cout << endl;
	cout << a.hang << " " << a.cot << endl;

}
void khoitao(ListGheNgoi*& list) {
	list->head = list->tail = NULL;
}
Node* createNode(GheNgoi value) {
	Node* p = new Node;
	if (p == NULL) {
		return NULL;
	}
	p->data = value;
	p->pNext = NULL;
}
bool isEmpty(ListGheNgoi*& list) {
	if (list->head == NULL && list->tail == NULL) {
		return true;
	}
	return false;
}
void addEmpty(ListGheNgoi*& list, GheNgoi value) {
	Node* p = createNode(value);
	list->head = list->tail = p;
}
void addLast(ListGheNgoi*& list, GheNgoi value) {
	if (isEmpty(list)) {
		addEmpty(list, value);
	}
	else {
		Node* p = createNode(value);
		list->tail->pNext = p;
		list->tail = p;
	}
}

ListGheNgoi* LoadData(const char* path) {
	ListGheNgoi* list = new ListGheNgoi;
	khoitao(list);
	ifstream reader(path, ios::binary | ios::in);
	int hang, cot;
	
	reader.read((char*)&hang, sizeof(int));
	reader.read((char*)&cot, sizeof(int));
	cout << hang << " " << cot;
	GheNgoi temp;
	while (reader.read((char*)&temp, sizeof(GheNgoi))) {
		addLast(list, temp);
	}
	return list;	
}
void SapXepListGheNgoi(ListGheNgoi* list, int(*soSanh)(GheNgoi, GheNgoi)) {
	for (Node* i = list->head; i != NULL; i = i->pNext) {
		for (Node* j = i->pNext; j != NULL; j = j->pNext) {
			if (soSanh(i->data, j->data) != 1) {
				GheNgoi temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}
int SoSanhGheNgoi(GheNgoi a, GheNgoi b) {
	if (a.hang < b.hang) {
		return a.hang < b.hang;
	}
	else {
		if (a.hang == b.hang) {
			return a.cot < b.cot;
		}
	}
	
}
char* tachHo(char a[], char b[]) {
	//
	char* result = new char[255];
	int index = 0;
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == ' ') {
			index = i;
			break;
		}
	}
	for (int i = 0; i < index; i++) {
		b[i] = a[i];
	}
	b[index] = '\0';

	return b;
	
}
void XuatSinhVien(ListGheNgoi* list) {
	for (Node* i = list->head; i != NULL; i = i->pNext) {
		xuatGheNgoi(i->data);
	}
}

ListGheNgoi* TimTheoHoKhuDeQuy(ListGheNgoi* list, const char* ho) {
	ListGheNgoi* result = new ListGheNgoi;
	khoitao(result);
	for (Node* i = list->head; i != NULL; i = i->pNext) {
		char temp[255];
		if (strcmp(tachHo(i->data.data.hoTen, temp), ho) == 0) {
			addLast(result, i->data);
		}
	}
	return result;
}

//ListGheNgoi* TimTheoDeQuy(ListGheNgoi* list, const char* ho) {
//	if()
//}

int main()
{
	const char* path = "data.bin";
	ListGheNgoi* lgn = LoadData(path);
	SapXepListGheNgoi(lgn, SoSanhGheNgoi);
	XuatSinhVien(lgn);
	cout << endl;
	

	/// Tìm các Sinh viên theo họ bằng cách khử đệ quy
	ListGheNgoi* lrs = TimTheoHoKhuDeQuy(lgn, "Tran");
	XuatSinhVien(lrs);
}