#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int>& a) {
    stack<int> b;
    if(a.empty() || a.size() <= 1) return;
    while(!a.empty()) {
        int temp = a.top();
        a.pop();
        while(!b.empty() && b.top() > temp) {
            a.push(b.top());
            b.pop();
        }
        b.push(temp);
    }
    a = b;
}

int main() {
    stack<int> a;
    a.push(1);
    a.push(5);
    a.push(3);
    a.push(3);
    a.push(8);
    sortStack(a);
    cout << a.top() << endl; a.pop();
    cout << a.top() << endl; a.pop();
    cout << a.top() << endl; a.pop();
    cout << a.top() << endl; a.pop();
    cout << a.top() << endl; a.pop();
}
