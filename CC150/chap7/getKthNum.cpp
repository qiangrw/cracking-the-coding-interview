#include <iostream>
#include <climits>
#include <functional>
#include <queue>
using namespace std;

int getKthNum(int k) {
    if(k < 0) return 0;
    queue<int> q3, q5, q7;
    q3.push(1);
    int value = 0;
    for(int i=0; i<=k; i++) {
        int v3 = q3.empty() ? INT_MAX : q3.front();
        int v5 = q5.empty() ? INT_MAX : q5.front();
        int v7 = q7.empty() ? INT_MAX : q7.front();
        value = min(v3, min(v5, v7));

        if(value == v3) {
            q3.push(3*value);
            q5.push(5*value);
            q3.pop();
        } else if(value == v5) {
            q5.push(5*value);
            q5.pop();
        } else {
            q7.pop();
        }
        q7.push(7*value);
    }
    return value;
}

int main() {
    cout << getKthNum(5) << endl;
    return 1;
}
