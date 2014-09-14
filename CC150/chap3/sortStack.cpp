#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int>& a, stack<int> &b) {
    if(a.empty() || a.size() <= 1) return;
    int n = a.size();    // elements need sort

    while(n>=1) {
        int minv = a.top();
        for(int i=0; i<n; i++) {
            int x = a.top();
            a.pop();
            if(minv > x) minv = x;
            b.push(x);
        }
        bool removed = false;
        a.push(minv);
        while(!b.empty()) {
            int x = b.top();
            b.pop();
            if(x != minv || removed) a.push(x);
            if(x == minv) removed = true;
        }
        n -= 1;
    }
}

int main() {
    stack<int> a;
    stack<int> b;
    a.push(1);
    a.push(5);
    a.push(3);
    a.push(3);
    a.push(8);
    sortStack(a, b);
    cout << a.top() << endl; a.pop();
    cout << a.top() << endl; a.pop();
    cout << a.top() << endl; a.pop();
    cout << a.top() << endl; a.pop();
    cout << a.top() << endl; a.pop();
}
