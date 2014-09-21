#include <iostream>
using namespace std;
// input: ABAAABBC interval = 3
// AB__A___A___AB___BC


int computeTime(const string& input, int interval) {
    int a = 0, b = 0, c = 0;
    int res = 0;
    for (const auto& s: input) {
        if (s == 'A') {
            res += a + 1;
            a = interval + 1;
        }
        if (s == 'B') {
            res += b + 1;
            b = interval + 1;
        }
        if (s == 'C') {
            res += c + 1;
            c = interval + 1;
        }
        if (a > 0) a -= 1;
        if (b > 0) b -= 1;
        if (c > 0) c -= 1;
    }
    return res;
}

int main() {
    cout << computeTime("ABAAABBC", 3) << endl;
}
