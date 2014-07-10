#include <iostream>
#include <stack>
using namespace std;

template <class T>
class minStack {
    private:
        stack<T> s;
        stack<T> m;
    public:
        void push(T x) {
            s.push(x);
            if(m.empty() || x < m.top()) {
                m.push(x);
            } else {
                m.push(m.top());
            }
        }
        void pop() {
            s.pop();
            m.pop();
        }
        T top() {
            return s.top();
        }
        T min() {
            return m.top();
        }
};

int main() {
    minStack<int> s;
    s.push(5);
    cout << s.min() << endl;
    s.push(6);
    cout << s.min() << endl;
    s.push(3);
    cout << s.min() << endl;
    s.push(7);
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
}
