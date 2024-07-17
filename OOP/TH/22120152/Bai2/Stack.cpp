#include "Stack.h"

void Stack::push(const string& val) {
    list.insert(0, val);
}

void Stack::pop() {
    list.erase(0);
}

string Stack::top() {
    return list.get(0);
}

int Stack::size() {
    return list.size();
}
