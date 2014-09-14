#include <iostream>
#include <stack>
#include <climits>
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
            } 
            /*else {
                m.push(m.top());
            }*/
        }
        void pop() {
            if(s.top() == min()){
                m.pop();
            }
            s.pop();
        }
        T top() {
            return s.top();
        }
        T min() {
            if(m.empty()) return INT_MAX;
            else return m.top();
        }
};

int main() {
    minStack<int> s;
    cout << s.min() << endl;
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
