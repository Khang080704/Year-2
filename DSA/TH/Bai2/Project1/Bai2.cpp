#include<iostream>
#include<string>
#include<sstream>
using namespace std;

struct Stack {
	int* list;
	int max;
	int size;
};
bool init(Stack& s, int n);
bool empty(Stack s);
bool full(Stack s);
bool push(Stack& s, int value);
bool pop(Stack& s);
int top(Stack s);

struct Queue {
	int* list;
	int max;
	int size;
};
bool initQueue(Queue& q, int n);
bool emptyQueue(Queue q);
bool fullQueue(Queue q);
bool pushQueue(Queue& q, int value);
bool popQueue(Queue& q);
int Front(Queue q);
int count(Queue q);
void print(Queue q);


int doUuTien(char a) {
	if (a == '+' || a == '-') {
		return 1;
	}
	else {
		if (a == '(') {
			return 0;
		}
		else {
			if (a == '*' || a == '/') {
				return 2;
			}
			else {
				return 3;
			}
		}
	}
}

string fix(string s) {
	stringstream ss(s);
	string a;
	string b;
	while (ss >> a) {
		b += a;
	}

	return b;
}

Queue solve(string s) {
	string input = fix(s);
	Stack a;
	init(a, 50);
	Queue b;
	initQueue(b, 50);
	int index = 0;

	for (int i = 0; i < input.length(); i = i + index) {
		if (input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/'
			&& input[i] != '(' && input[i] != ')') {
			int j = 0;
			string temp = "";
			while (input[i + j] != '+' && input[i + j] != '-' && input[i + j] != '*' && input[i + j] != '/'
				&& input[i + j] != '(' && input[i + j] != ')' && input[i + j] != '\0') {
				temp += input[i + j];
				j++;
			}
			index = j;
			int value = stoi(temp);
			pushQueue(b, value);
		}
		else {
			if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
				if (doUuTien(input[i]) > doUuTien(top(a))) {
					push(a, input[i]);
				}
				else {
					while (!empty(a) && top(a) != '(' && doUuTien(input[i]) <= doUuTien(top(a))) {
						pushQueue(b, (int)top(a));
						pop(a);
					}
					push(a, input[i]);
				}
				index = 1;
			}
			else {
				if (input[i] == '(') {
					push(a, input[i]);
				}
				else {
					while (top(a) != '(') {
						pushQueue(b, (int)top(a));
						pop(a);
					}
					pop(a);
				}
				index = 1;
			}
		}
	}

	while (!empty(a)) {
		pushQueue(b, (int)top(a));
		pop(a);
	}

	return b;
}

double calculate(string s) {
	Queue postfix = solve(s);
	Stack computer;
	init(computer, 50);
	double result = 0;

	while (!emptyQueue(postfix)) {
		if (Front(postfix) != '+' && Front(postfix) != '-' && Front(postfix) != '*'
			&& Front(postfix) != '/') {
			push(computer, Front(postfix));
		}
		else {
			switch (Front(postfix))
			{
			case 43: {
				int x = top(computer);
				pop(computer);
				int y = top(computer);
				pop(computer);
				result = 1.0 * (x + y);
				push(computer, result);
				break;
			}
			case 45: {
				int x = top(computer);
				pop(computer);
				int y = top(computer);
				pop(computer);
				result = 1.0 * (y - x);
				push(computer, result);
				break;
			}
			case 42: {
				int x = top(computer);
				pop(computer);
				int y = top(computer);
				pop(computer);
				result = 1.0 * x * y;
				push(computer, result);
				break;
			}
			case 47: {
				int x = top(computer);
				pop(computer);
				int y = top(computer);
				pop(computer);
				result = 1.0 * y / x;
				push(computer, result);
				break;
			}
			}
		}
		popQueue(postfix);
	}
	return result;
}

int main()
{
	string s;
	getline(cin, s);
	cout << calculate(s);

}

bool init(Stack& s, int n) {
	s.list = new int[n];
	if (s.list == NULL)
		return false;
	else {
		s.max = n;
		s.size = 0;
		return true;
	}
}

bool empty(Stack s) {
	if (s.size == 0) {
		return true;
	}
	return false;
}

bool full(Stack s) {
	if (s.size == s.max)
		return true;
	return false;
}

bool push(Stack& s, int value) {
	if (full(s))
		return false;
	s.list[s.size] = value;
	s.size++;
	return true;
}

bool pop(Stack& s) {
	if (empty(s))
		return false;
	s.size--;
	return true;
}

int top(Stack s) {
	if (empty(s)) {
		return INT_MIN;
	}
	else {
		int value = s.list[s.size - 1];
		return value;
	}
}

bool initQueue(Queue& q, int n) {
	q.list = new int[n];
	if (q.list == NULL) {
		return false;
	}
	q.max = n;
	q.size = 0;
	return true;
}

bool emptyQueue(Queue q) {
	if (q.size == 0)
		return true;
	return false;
}

bool fullQueue(Queue q) {
	if (q.size == q.max)
		return true;
	return false;
}

bool pushQueue(Queue& q, int value) {
	if (fullQueue(q)) {
		return false;
	}
	else {
		q.list[q.size] = value;
		q.size++;
		return true;
	}
}

bool popQueue(Queue& q) {
	if (emptyQueue(q)) {
		return false;
	}
	else {
		for (int i = 0; i < q.size - 1; i++) {
			q.list[i] = q.list[i + 1];
		}
		q.size--;
	}
}

int Front(Queue q) {
	if (emptyQueue(q)) {
		return INT_MIN;
	}
	else {
		return q.list[0];
	}
}

void print(Queue q) {
	Queue temp = q;
	while (!emptyQueue(temp)) {
		cout << Front(temp) << " ";
		popQueue(temp);
	}

}